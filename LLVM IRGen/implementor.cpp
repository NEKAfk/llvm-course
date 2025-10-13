#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <functional>
#include <ranges>
#include <numeric>

#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Constants.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"
#include "variables.h"

class implementor {

public:
    implementor(std::string path) : Context{}, Err{}, Module{llvm::parseIRFile(path, Err, Context)} {}

    void implement(std::string dst) {
        std::ofstream dst_file(dst);

        buildGraph();
        buildTopSort();
        dst_file << writeHeader().str()
                 << writeContext().str()
                 << writeGlobals().str()
                 << initBasicTypes().str()
                 << writeFunctions().str()
                 << writeEngine().str();
        dst_file << "}\n";
    }

private:
    std::stringstream writeHeader() {
        std::stringstream out;
        for (const auto& include : meta::includes) {
            out << "#include \"" << include << "\"\n";
        }
        out << "\nint main() {\n"
            << "\tusing namespace llvm;\n\n";
        return out;
    }

    std::stringstream writeContext() {
        std::stringstream out;
        out << "\tLLVMContext context;\n"
            << "\tModule module(\"" << "some_cool_module_name" << "\", context);\n"
            << "\tIRBuilder builder(context);\n";
        return out;
    }

    // no globals
    std::stringstream writeGlobals() {
        return {};
    }

    std::stringstream initBasicTypes() {
        std::stringstream out;
        for (const auto& [name, type] : meta::types) {
            out << "\tType *"<< name << "Type = Type::get" << name << "Ty(context);\n"
                << "\tType *" << name << "PtrType = " << name << "Type->getPointerTo();\n";
        }
        out << '\n';
        return out;
    }

    std::stringstream writeFunctions() {
        std::stringstream out;
        for (auto  &F : *Module) {
            out << implFunction(F).str();
        }

        for (auto  &F : *Module) {
            if (F.isDeclaration()) continue;
            out << writeBasicBlocks(F).str();
        }
        return out;
    }

    std::stringstream implFunction(llvm::Function &F) {
        std::stringstream out;
        auto fName = getCorrectName(F);

        out << "\tArrayRef<Type*> " << fName << "ParamTypes = {" << getParamTypes(F).str() << "};\n"
            << "\tFunctionType *" << fName << "Type = FunctionType::get(" << getReturnType(F).str() << ", " << fName << "ParamTypes, false);\n";

        out << getFunctionAttributes(F).str() << '\n';

        if (F.isDeclaration()) {
            out << "\tFunctionCallee " << fName << "Func = module.getOrInsertFunction(\"" << F.getName().str() << "\", " << fName << "Type, " << fName << "Attributes);\n\n";
        } else {
            out << "\tFunction *" << fName << "Func = Function::Create(" << fName << "Type, Function::ExternalLinkage, \"" << F.getName().str() << "\", &module);\n";
            out << "\t" << fName << "Func->setAttributes(" << fName << "Attributes);\n\n";
        }
        return out;
    }

    std::stringstream writeBasicBlocks(llvm::Function &F) {
        phiNodes.clear();
        std::stringstream out;
        for (auto& B : F) {
            out << "\tBasicBlock *BB" << blocks.size() << "= BasicBlock::Create(context, \"\", " << getCorrectName(F) << "Func);\n";
            blocks[&B] = std::string("BB") + std::to_string(blocks.size());
        }
        out << '\n';

        for (auto& B : F) {
            out << writePhiNodes(B).str();
        }

        for (auto *B : std::views::reverse(topsort)) {
            out << writeInstructions(*B).str();
        }

        out << linkPhiNodes().str();

        return out;
    }

    std::stringstream writePhiNodes(llvm::BasicBlock &B) {
        std::stringstream out;
        out << "\tbuilder.SetInsertPoint(" << blocks[&B] << ");\n";
        for (auto& I : B) {
            if (auto *Phi = llvm::dyn_cast<llvm::PHINode>(&I)) {
                instructionsWithUses[static_cast<llvm::Value*>(&I)] = std::string("I") + std::to_string(instructionsWithUses.size());
                phiNodes.push_back(Phi);
                out << "\tValue *" << instructionsWithUses[static_cast<llvm::Value*>(&I)] << " = builder.CreatePHI("
                    << meta::getTypeName(Context, Phi->getType()) << ", "
                    << Phi->getNumIncomingValues() << ");\n";
            }
        }
        out << '\n';
        return out;
    }

    std::stringstream linkPhiNodes() {
        std::stringstream out;
        for (auto *Phi : phiNodes) {
            for (size_t i = 0; i < Phi->getNumIncomingValues(); ++i) {
                out << "\tstatic_cast<PHINode*>(" << instructionsWithUses[static_cast<llvm::Value*>(Phi)] << ")->addIncoming("
                    << getConstOrUse(Phi->getIncomingValue(i)) << ", "
                    << blocks[Phi->getIncomingBlock(i)] << ");\n";
            }
            out << '\n';
        }
        return out;
    }

    std::stringstream writeInstructions(llvm::BasicBlock &B) {
        std::stringstream out;
        out << "\tbuilder.SetInsertPoint(" << blocks[&B] << ");\n";
        for (auto& I : B) {
            if (auto *Phi = llvm::dyn_cast<llvm::PHINode>(&I)) {
                continue;
            }
            out << "\t";
            if (I.getNumUses() != 0) {
                instructionsWithUses[static_cast<llvm::Value*>(&I)] = std::string("I") + std::to_string(instructionsWithUses.size());
                out << "Value *" << instructionsWithUses[static_cast<llvm::Value*>(&I)] << " = ";
            }
            out << "builder.Create";
            if (auto *BiOp = llvm::dyn_cast<llvm::BinaryOperator>(&I)) {
                switch (BiOp->getOpcode()) {
                    case llvm::Instruction::Add:
                        out << "Add("
                            << getConstOrUse(BiOp->getOperand(0)) << ", "
                            << getConstOrUse(BiOp->getOperand(1)) << ", "
                            << "\"\", "
                            << meta::boolToStr(BiOp->hasNoUnsignedWrap()) << ", "
                            << meta::boolToStr(BiOp->hasNoSignedWrap());
                        break;
                    case llvm::Instruction::Mul:
                        out << "Mul("
                            << getConstOrUse(BiOp->getOperand(0)) << ", "
                            << getConstOrUse(BiOp->getOperand(1)) << ", "
                            << "\"\", "
                            << meta::boolToStr(BiOp->hasNoUnsignedWrap()) << ", "
                            << meta::boolToStr(BiOp->hasNoSignedWrap());
                        break;
                    case llvm::Instruction::SRem:
                        out << "SRem("
                            << getConstOrUse(BiOp->getOperand(0)) << ", "
                            << getConstOrUse(BiOp->getOperand(1));
                        break;
                    case llvm::Instruction::Shl:
                        out << "Shl("
                            << getConstOrUse(BiOp->getOperand(0)) << ", "
                            << getConstOrUse(BiOp->getOperand(1));
                        break;
                    case llvm::Instruction::And:
                        out << "And("
                            << getConstOrUse(BiOp->getOperand(0)) << ", "
                            << getConstOrUse(BiOp->getOperand(1));
                        break;
                    case llvm::Instruction::Or:
                        out << "Or("
                            << getConstOrUse(BiOp->getOperand(0)) << ", "
                            << getConstOrUse(BiOp->getOperand(1));
                        break;
                    case llvm::Instruction::Xor:
                        out << "Xor("
                            << getConstOrUse(BiOp->getOperand(0)) << ", "
                            << getConstOrUse(BiOp->getOperand(1));
                        break;
                }
            } else if (auto *Br = llvm::dyn_cast<llvm::BranchInst>(&I)) {
                if (Br->isUnconditional()) {
                    out << "Br("
                        << blocks[Br->getSuccessor(0)];
                } else {
                    out << "CondBr("
                        << getConstOrUse(Br->getCondition()) << ", "
                        << blocks[Br->getSuccessor(0)] << ", "
                        << blocks[Br->getSuccessor(1)];
                }
            } else if (auto *Call = llvm::dyn_cast<llvm::CallInst>(&I)) {
                bool isDecl = Call->getCalledFunction()->isDeclaration();
                out << "Call("
                    << (isDecl ? "" : "FuncionCallee(")
                    << getCorrectName(*Call->getCalledFunction()) << "Func"
                    << (isDecl ? "" : ")") << ", "
                    << "{" << getCallArgList(Call).str() << "}";
            } else if (auto *ICmp = llvm::dyn_cast<llvm::ICmpInst>(&I)) {
                out << "ICmp("
                    << "CmpInst::Predicate::ICMP_" << 
                        (ICmp->getPredicate() == llvm::CmpInst::Predicate::ICMP_EQ ? "EQ" : "NE") << ", "
                    << getConstOrUse(ICmp->getOperand(0)) << ", "
                    << getConstOrUse(ICmp->getOperand(1));
            } else if (auto *GEP = llvm::dyn_cast<llvm::GetElementPtrInst>(&I)) {
                out << "GEP("
                    << getDefaultOrArrayType(GEP->getSourceElementType()) << ", "
                    << instructionsWithUses[GEP->getPointerOperand()] << ", "
                    << "{" << getGEPIdxList(GEP, 1).str() << "}, "
                    << "\"\", "
                    << "GEPNoWrapFlags::fromRaw(" << GEP->getNoWrapFlags().getRaw() << ")";
            } else if (auto *UOp = llvm::dyn_cast<llvm::UnaryInstruction>(&I)) {
                if (auto *Trunc = llvm::dyn_cast<llvm::TruncInst>(UOp)) {
                    out << "Trunc("
                    << instructionsWithUses[Trunc->getOperand(0)] << ", "
                    << meta::getTypeName(Context, Trunc->getDestTy()) << ", "
                    << "\"\", "
                    << meta::boolToStr(Trunc->hasNoUnsignedWrap()) << ", "
                    << meta::boolToStr(Trunc->hasNoSignedWrap());
                } else if (auto *ZExt = llvm::dyn_cast<llvm::ZExtInst>(UOp)) {
                    out << "ZExt("
                    << instructionsWithUses[ZExt->getOperand(0)] << ", "
                    << meta::getTypeName(Context, ZExt->getDestTy()) << ", "
                    << "\"\", "
                    << meta::boolToStr(ZExt->hasNonNeg());
                } else if (auto *Alloca = llvm::dyn_cast<llvm::AllocaInst>(UOp)) {
                    out << "Alloca("
                        << getDefaultOrArrayType(Alloca->getAllocatedType()); // TODO: do
                } else if (auto *Load = llvm::dyn_cast<llvm::LoadInst>(UOp)) {
                    out << "Load("
                    << meta::getTypeName(Context, Load->getAccessType()) << ", "
                    << instructionsWithUses[Load->getPointerOperand()];
                }
            } else if (auto *Store = llvm::dyn_cast<llvm::StoreInst>(&I)) {
                out << "Store("
                    << getConstOrUse(Store->getValueOperand()) << ", "
                    << instructionsWithUses[Store->getPointerOperand()];
            } else if (auto *Select = llvm::dyn_cast<llvm::SelectInst>(&I)) {
                out << "Select("
                    << getConstOrUse(Select->getCondition()) << ", "
                    << getConstOrUse(Select->getTrueValue()) << ", "
                    << getConstOrUse(Select->getFalseValue());
            } else if (auto *Ret = llvm::dyn_cast<llvm::ReturnInst>(&I)) {
                // No return
            }
            out << ");\n";
        }
        out << '\n';
        return out;
    }

    std::stringstream getFunctionAttributes(llvm::Function& F) {
        std::stringstream out;
        auto fName = getCorrectName(F);
        out << "\tllvm::AttributeList " << fName << "Attributes;\n";
        for (size_t attr = 1; attr < 100; ++attr) {
            bool fnAttr = F.hasFnAttribute(static_cast<llvm::Attribute::AttrKind>(attr));
            bool fnOrRetAttr = fnAttr || F.hasRetAttribute(static_cast<llvm::Attribute::AttrKind>(attr));
            if (fnOrRetAttr) {
                out << "\t" << fName << "Attributes.add" << (fnAttr ? "Fn" : "Ret") << "Attribute(context, static_cast<llvm::Attribute::AttrKind>(" << attr << "));\n";
            }

            for (size_t argNo = 0; argNo < F.arg_size(); ++argNo) {
                if (F.hasParamAttribute(argNo, static_cast<llvm::Attribute::AttrKind>(attr))) {
                    out << "\t" << fName << "Attributes.addParamAttribute(context, " << argNo << ", static_cast<llvm::Attribute::AttrKind>(" << attr << "));\n";
                }
            }
        }
        return out;
    }

    std::stringstream getReturnType(llvm::Function& F) {
        std::stringstream out;
        out << meta::getTypeName(Context, F.getReturnType());
        return out;
    }

    std::stringstream getParamTypes(llvm::Function& F) {
        std::stringstream out;

        for (auto& arg : F.args()) {
            out << meta::getTypeName(Context, arg.getType()) << ", ";
        }
        return out;
    }

    std::stringstream getGEPIdxList(llvm::GetElementPtrInst *Op, size_t i = 0) {
        std::stringstream out;
        for (; i < Op->getNumOperands(); ++i) {
            out << getConstOrUse(Op->getOperand(i)) << ", ";
        }
        return out;
    }

    std::stringstream getCallArgList(llvm::CallInst *Op) {
        std::stringstream out;
        for (auto &U : Op->args()) {
            out << getConstOrUse(U.get()) << ", ";
        }
        return out;
    }

    std::string getCorrectName(auto& E) {
        std::string res = E.getName().str();
        std::replace(res.begin(), res.end(), '.', '_');
        return res;
    }

    std::string getConstOrUse(llvm::Value *val) {
        if (instructionsWithUses.contains(val)) {
            return instructionsWithUses[val];
        } else if (auto *CI = llvm::dyn_cast<llvm::ConstantInt>(val)) {
            for (const auto &[name, getter] : meta::types) {
                if (getter(Context) == CI->getType()) {
                    return (std::stringstream{} << "builder.get" << name << "(" << CI->getSExtValue() << ")").str();
                }
            }
        }
        std::unreachable();
    }

    std::string getDefaultOrArrayType(llvm::Type* type) {
        if (!type->isArrayTy()) {
            return meta::getTypeName(Context, type);
        } else {
            return (std::stringstream{} << "ArrayType::get(" << getDefaultOrArrayType(type->getArrayElementType()) << ", " << type->getArrayNumElements() << ")").str();
        }
    }

    std::stringstream writeEngine() { // for app only
        std::stringstream out;
        out << "\tmodule.print(outs(), nullptr);\n"
            << "\touts() << \"[VERIFICATION] \" << (verifyModule(module, &outs()) ? \"FAIL\\n\\n\" : \"OK\\n\\n\");\n"
            << "\tInitializeNativeTarget();\n"
            << "\tInitializeNativeTargetAsmPrinter();\n"
            << "\tExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(&module)).create();\n"
            << "\tee->InstallLazyFunctionCreator([](const std::string &fnName) {\n";
            
        if (!meta::functions.empty()) {
            out << "\t\t";
            for (size_t i = 0; i < meta::functions.size(); ++i) {
                out << "if (fnName == \"" << meta::functions[i] << "\") {\n"
                    << "\t\t\treturn reinterpret_cast<void*>(" << meta::functions[i] << ");\n"
                    << "\t\t}";
                if (i + 1 != meta::functions.size()) {
                    out << " else ";
                }
            }
            out << '\n';
        }

        out << "\t});\n"
            << "\tee->finalizeObject();\n"
            << "\tArrayRef<GenericValue> noargs;\n"
            << "\tsimInit();\n"
            << "\tee->runFunction(appFunc, noargs);\n"
            << "\tsimExit();\n";
        return out;
    }

    void buildGraph() {
        for (auto &F : *Module) {
            if (F.isDeclaration()) {
                continue;
            }
            for (auto &B : F) {
                for (auto &I: B) {
                    if (llvm::dyn_cast<llvm::PHINode>(&I)) {
                        continue;
                    }
                    
                    for (auto &U : I.operands()) {
                        if (auto *Phi = dyn_cast<llvm::PHINode>(U.get())) {
                            continue;
                        } else if (auto *In = dyn_cast<llvm::Instruction>(U.get())) {
                            graph[In->getParent()].insert(&B);
                        }
                    }
                }
            }
        }
    }

    void buildTopSort() {
        for (auto *I : graph | std::views::keys) {
            buildTopSortImpl(I);
        }
    }

    void buildTopSortImpl(llvm::BasicBlock *I) {
        if (vis.contains(I)) {
            return;
        }
        vis.insert(I);
        for (auto *In : graph[I]) {
            buildTopSortImpl(In);
        }
        topsort.push_back(I);
    }

    llvm::LLVMContext Context;
    llvm::SMDiagnostic Err;
    std::unique_ptr<llvm::Module> Module;

    std::vector<llvm::PHINode*> phiNodes;
    std::map<llvm::BasicBlock*, std::string> blocks;
    std::map<llvm::Value*, std::string> instructionsWithUses;

    std::map<llvm::BasicBlock *, std::set<llvm::BasicBlock*>> graph;
    std::set<llvm::BasicBlock *> vis;

    std::vector<llvm::BasicBlock*> topsort;
};

int main() {
    implementor("../SDL/IR/app.ll").implement("ir_gen_app.cpp");
}