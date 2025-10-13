#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

#include <ranges>
#include <set>
#include <map>
#include <vector>
#include <string>

struct MyModPass : public llvm::PassInfoMixin<MyModPass> {
  llvm::PreservedAnalyses run(llvm::Module &M, llvm::ModuleAnalysisManager &AM) {
    using namespace llvm;

    outs() << "[Module] " << M.getName() << '\n';

    LLVMContext &Ctx = M.getContext();
    IRBuilder builder(Ctx);

    Type *int8PtrTy = Type::getInt8Ty(Ctx)->getPointerTo();
    Type *voidType = Type::getVoidTy(Ctx);
    ArrayRef<Type *> TraceLogParamTypes{int8PtrTy, int8PtrTy};
    FunctionType *TraceLogFuncType =
        FunctionType::get(voidType, TraceLogParamTypes, false);
    FunctionCallee TraceLogFunc =
        M.getOrInsertFunction("TraceLogger", TraceLogFuncType);

    std::vector<Instruction *> operands;
    std::set<PHINode *> set;
    std::map<const char*, Value *> opNames;

    for (auto &F : M) {
      if (F.isDeclaration()) {
        continue;
      }

      for (auto &B : F) {
        for (auto &I : B) {
          if (auto *Phi = dyn_cast<PHINode>(&I)) {
            continue;
          }

          operands.clear();

          for (auto &U : I.operands()) {
            if (auto *Phi = dyn_cast<PHINode>(U.get())) {
              set.clear();
              getRecursivePhiAlternatives(set, operands, Phi);
            } else if (auto *In = dyn_cast<Instruction>(U.get())) {
              operands.push_back(In);
            }
          }

          builder.SetInsertPoint(&I);

          if (!opNames.contains(I.getOpcodeName())) {
            opNames[I.getOpcodeName()] = builder.CreateGlobalString(I.getOpcodeName());
          }
          for (auto *In : std::views::reverse(operands)) {
            std::string InOpcodeName(In->getOpcodeName());
            if (!opNames.contains(In->getOpcodeName())) {
              opNames[In->getOpcodeName()] = builder.CreateGlobalString(In->getOpcodeName());
            }
            builder.CreateCall(TraceLogFunc, {opNames[I.getOpcodeName()], opNames[In->getOpcodeName()]});
          }
        }
      }
    }
    return PreservedAnalyses::none();
  };

private:
  void getRecursivePhiAlternatives(std::set<llvm::PHINode *> &set,
                                   std::vector<llvm::Instruction *> &phiAlternatives, llvm::PHINode *Phi) {
    using namespace llvm;

    if (set.contains(Phi)) {
      phiAlternatives.push_back(Phi);
      return;
    }
    
    set.insert(Phi);
    for (auto &U : Phi->incoming_values()) {
      Value *val = U.get();
      if (auto *PrevPhi = dyn_cast<PHINode>(val)) {
        getRecursivePhiAlternatives(set, phiAlternatives, PrevPhi);
      }
      else if (auto *I = dyn_cast<Instruction>(val)) {
        phiAlternatives.push_back(I);
      }
    }
  }
};

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "MyPlugin", "0.0.1", [](llvm::PassBuilder &PB) {
            PB.registerOptimizerLastEPCallback([](llvm::ModulePassManager &MPM, auto...) {
              MPM.addPass(MyModPass{});
              return true; });
          }};
}
