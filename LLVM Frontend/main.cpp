#include "../SDL/include/sim.h"
#include "generated/GrammarLexer.h"
#include "generated/GrammarParser.h"
#include "generated/GrammarVisitor.h"

#include "antlr4-runtime.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

#include <any>
#include <cstddef>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace llvm;

struct TreeLLVMWalker : public GrammarVisitor {
  std::map<std::string, Value *> globalVars;
   std::map<std::string, ArrayType *> arrTypes;
  std::vector<std::map<std::string, std::pair<bool, Value *>>> vars;
  Function *currFunc;
  LLVMContext *ctxLLVM;
  Module *module;
  IRBuilder<> *builder;
  bool interpretMode;
  Type *int64Type;
  Type *int32Type;
  Type *int8Type;
  Type *int1Type;
  Type *voidType;
  TreeLLVMWalker(LLVMContext *ctxLLVM, IRBuilder<> *builder, Module *module,
                 bool interpretMode)
      : ctxLLVM(ctxLLVM), builder(builder), module(module),
        interpretMode(interpretMode) {
    int64Type = Type::getInt64Ty(*ctxLLVM);
    int32Type = Type::getInt32Ty(*ctxLLVM);
    int8Type = Type::getInt8Ty(*ctxLLVM);
    int1Type = Type::getInt1Ty(*ctxLLVM);
    voidType = Type::getVoidTy(*ctxLLVM);
  }

  void regGraphicFuncs() {
    // declare void @putPixel(i32, i32, i32)
    ArrayRef<Type *> putPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType *putPixelType =
        FunctionType::get(voidType, putPixelParamTypes, false);
    module->getOrInsertFunction("putPixel", putPixelType);

    // declare void @flush()
    FunctionType *flushType = FunctionType::get(voidType, false);
    module->getOrInsertFunction("flush", flushType);

    // declare i32 @rand()
    FunctionType *randType = FunctionType::get(int32Type, false);
    module->getOrInsertFunction("rand", randType);
  }

  void regGraphicFuncsIntr() {
    // declare void @llvm.sim.putpixel(i32, i32, i32)
    ArrayRef<Type *> putPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType *putPixelIntrType =
        FunctionType::get(voidType, putPixelParamTypes, false);
    FunctionCallee putPixelIntr =
        module->getOrInsertFunction("llvm.sim.putpixel", putPixelIntrType);

    // define void @putPixel(i32 %0, i32 %1, i32 %2) {
    FunctionType *putPixelType =
        FunctionType::get(voidType, putPixelParamTypes, false);
    Function *putPixelFunc = Function::Create(
        putPixelType, Function::ExternalLinkage, "putPixel", module);
    // entry:
    builder->SetInsertPoint(
        BasicBlock::Create(*ctxLLVM, "entry", putPixelFunc));
    // call void @llvm.sim.putpixel(i32 %0, i32 %1, i32 %2)
    builder->CreateCall(putPixelIntr,
                        {putPixelFunc->getArg(0), putPixelFunc->getArg(1),
                         putPixelFunc->getArg(2)});

    // declare void @llvm.sim.flush()
    FunctionType *flushIntrType = FunctionType::get(voidType, false);
    FunctionCallee flushIntr =
        module->getOrInsertFunction("llvm.sim.flush", flushIntrType);

    // define void @flush() {
    FunctionType *flushType = FunctionType::get(voidType, false);
    Function *flushFunc = Function::Create(
        flushType, Function::ExternalLinkage, "flush", module);
    // entry:
    builder->SetInsertPoint(
        BasicBlock::Create(*ctxLLVM, "entry", flushFunc));
    // call void @llvm.sim.flush()
    builder->CreateCall(flushIntr);

    // declare i32 @llvm.sim.rand()
    FunctionType *randIntrType = FunctionType::get(int32Type, false);
    FunctionCallee randIntr =
        module->getOrInsertFunction("llvm.sim.rand", randIntrType);

    // define i32 @rand() {
    FunctionType *randType = FunctionType::get(int32Type, false);
    Function *randFunc = Function::Create(
        flushType, Function::ExternalLinkage, "rand", module);

    // entry:
    builder->SetInsertPoint(BasicBlock::Create(*ctxLLVM, "entry", randFunc));
    // call void @llvm.sim.rand()
    Value *ret = builder->CreateCall(randIntr);
    // ret i32
    builder->CreateRet(ret);
  }

  std::any visitProgram(GrammarParser::ProgramContext *ctx) override {
    outs() << "visitProgram\n";
    if (interpretMode) {
      regGraphicFuncs();
    } else {
      regGraphicFuncsIntr();
    }
    globalVars = std::map<std::string, Value *>{
        {"Y_SIZE", builder->getInt32(256)}, {"X_SIZE", builder->getInt32(512)}};
    for (auto it : ctx->funDecl()) {
      visitFunDecl(it);
    }
    return nullptr;
  }

  std::any visitFunDecl(GrammarParser::FunDeclContext *ctx) override {
    std::string name = ctx->ID()[0]->getText();
    vars.emplace_back();

    std::vector<Type *> funcParamTypes(ctx->ID().size() - 1, int32Type);

    FunctionType *funcType = FunctionType::get((ctx->VOID()) ? voidType : int32Type, funcParamTypes, false);
    Function *func =
        Function::Create(funcType, Function::ExternalLinkage, name, module);

    BasicBlock *entryBB = BasicBlock::Create(*ctxLLVM, "entry", func);
    builder->SetInsertPoint(entryBB);
    currFunc = func;

    for (int arg = 1; arg < ctx->ID().size(); arg++) {
      Value* val = builder->CreateAlloca(int32Type);
      builder->CreateStore(func->getArg(arg - 1), val);
      registerVar(ctx->ID()[arg]->getText(), val);
    }

    for (auto it : ctx->line()) {
      visitLine(it);
    }
    vars.pop_back();
    if (builder->GetInsertBlock()->empty()) {
        builder->GetInsertBlock()->eraseFromParent();
    }
    return nullptr;
  }

  std::any visitLine(GrammarParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  std::any visitCreate(GrammarParser::CreateContext *ctx) override {
    return visitChildren(ctx);
  }

  std::any visitVarDecl(GrammarParser::VarDeclContext *ctx) override {
    std::string name = ctx->ID()->getText();
    Value *val = std::any_cast<Value *>(visitExpr(ctx->expr()));
    Value *var = builder->CreateAlloca(int32Type);
    builder->CreateStore(val, var);
    registerVar(name, var);
    return var;
  }

  std::any visitArrDecl(GrammarParser::ArrDeclContext *ctx) override {
    std::string name = ctx->ID()->getText();

    int mulDim = 1;
    int size = std::stoi(ctx->INT().back()->getText());
    ArrayType *arrType =
        ArrayType::get(int32Type,size);
    mulDim *= size;
    for (int arg = ctx->INT().size() - 2; arg >= 0; arg--) {
      int size = std::stoi(ctx->INT()[arg]->getText());
      arrType = ArrayType::get(arrType, size);
      mulDim *= size;
    }
    Value *arr = builder->CreateAlloca(arrType);
    builder->CreateMemSet(arr, builder->getInt8(0), builder->getInt64(mulDim * 4), MaybeAlign{});
    registerVar(name, arr);
    arrTypes[name] = arrType;
    return arr;
  }

  std::any visitReturnExpr(GrammarParser::ReturnExprContext *ctx) override {
    BasicBlock* retBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    BasicBlock* afterRetBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    if (ctx->expr()) {
      Value* val = std::any_cast<Value *>(visitExpr(ctx->expr()));
      builder->CreateBr(retBB);
      builder->SetInsertPoint(retBB);
      Value* res = (Value *)builder->CreateRet(val);
      builder->SetInsertPoint(afterRetBB);
      return res;
    } else {
      builder->CreateBr(retBB);
      builder->SetInsertPoint(retBB);
      builder->CreateRetVoid();
      builder->SetInsertPoint(afterRetBB);
      return nullptr;
    }
  }

  std::any visitAssign(GrammarParser::AssignContext *ctx) override {
    Value *expr = std::any_cast<Value *>(visitExpr(ctx->expr().back()));
    if (ctx->expr().size() == 1) {
      auto [isPHI, val] = searchVar(ctx->ID()->getText());
      builder->CreateStore(expr, val);
      return val;
    } else {
      auto [isPHI, arr] = searchVar(ctx->ID()->getText());
      std::vector<Value *> idx;
      idx.push_back(builder->getInt32(0));
      for (int arg = 0; arg < ctx->expr().size() - 1; arg++) {
        idx.push_back(std::any_cast<Value *>(visitExpr(ctx->expr()[arg])));
      }
      Value *val = builder->CreateGEP(arrTypes[ctx->ID()->getText()], arr, idx);
      builder->CreateStore(expr, val);
      return val;
    }
  }

  std::any visitIfExpr(GrammarParser::IfExprContext *ctx) override {
    vars.emplace_back();
    Value *cond = std::any_cast<Value *>(visitExpr(ctx->expr()));
    BasicBlock *condBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->CreateBr(condBB);
    BasicBlock *trueBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    
    builder->SetInsertPoint(trueBB);
    for (auto it : ctx->line()) {
      visitLine(it);
    }

    BasicBlock *falseBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->CreateBr(falseBB);

    builder->SetInsertPoint(condBB);
    builder->CreateCondBr(cond, trueBB, falseBB);
    builder->SetInsertPoint(falseBB);
    vars.pop_back();
    return nullptr;
  }

  std::any visitWhileExpr(GrammarParser::WhileExprContext *ctx) override {
    vars.emplace_back();
    BasicBlock *condBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->CreateBr(condBB);
    BasicBlock *bodyBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->SetInsertPoint(bodyBB);
    for (auto it : ctx->line()) {
      visitLine(it);
    }
    builder->CreateBr(condBB);

    BasicBlock *exitBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->SetInsertPoint(condBB);
    Value *cond = std::any_cast<Value *>(visitExpr(ctx->expr()));
    builder->CreateCondBr(cond, bodyBB, exitBB);
    builder->SetInsertPoint(exitBB);
    vars.pop_back();
    return nullptr;
  }

  std::any visitForExpr(GrammarParser::ForExprContext *ctx) override {
    forExprImpl(ctx, 0);
    return nullptr;
  }

  void forExprImpl(GrammarParser::ForExprContext *ctx, int arg) {
    vars.emplace_back();
    if (arg == ctx->ID().size()) {
      for (auto it : ctx->line()) {
        visitLine(it);
      }
      vars.pop_back();
      return;
    }

    BasicBlock* curBB = builder->GetInsertBlock();
    Value* firstVal = std::any_cast<Value*>(visitExpr(ctx->expr(2*arg)));

    BasicBlock *condBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->CreateBr(condBB);

    builder->SetInsertPoint(condBB);
    Value* val = builder->CreatePHI(int32Type, 2);
    registerVar(ctx->ID()[arg]->getText(), val, true);

    BasicBlock *bodyBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->SetInsertPoint(bodyBB);

    forExprImpl(ctx, arg + 1);
    Value* newVal = builder->CreateAdd(val,
                        builder->getInt32(1));
    builder->CreateBr(condBB);

    static_cast<PHINode*>(val)->addIncoming(firstVal, curBB);
    static_cast<PHINode*>(val)->addIncoming(newVal, builder->GetInsertBlock());
    
    BasicBlock *exitBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    builder->SetInsertPoint(condBB);
    Value *cond = builder->CreateICmpSLT(
      val,
      std::any_cast<Value *>(visitExpr(ctx->expr()[2*arg + 1])));
    builder->CreateCondBr(cond, bodyBB, exitBB);
    builder->SetInsertPoint(exitBB);
    vars.pop_back();
  }

  std::any visitFunParams(GrammarParser::FunParamsContext *ctx) override {
    return nullptr;
  }

  std::any visitExpr(GrammarParser::ExprContext *ctx) override {
    if (ctx->ID()) {
      if (!ctx->funParams()) {
        std::string name = ctx->ID()->getText();
        if (globalVars.find(name) != globalVars.end()) {
          return globalVars[name];
        } else if (ctx->expr().empty()) {
          auto [isPHI, val] = searchVar(name);
          return isPHI ? val : (Value*) builder->CreateLoad(int32Type, val);
        } else {
          auto [isPHI, arr] = searchVar(ctx->ID()->getText());
          std::vector<Value *> idx;
          idx.push_back(builder->getInt32(0));
          for (int arg = 0; arg < ctx->expr().size(); arg++) {
            idx.push_back(std::any_cast<Value *>(visitExpr(ctx->expr()[arg])));
          }
          Value *val = builder->CreateGEP(arrTypes[ctx->ID()->getText()], arr, idx);
          return (Value*) builder->CreateLoad(int32Type, val);
        }
      } else {
        auto* fpCtx = ctx->funParams();
        std::string fn = ctx->ID()->getText();
        Function* fun = module->getFunction(ctx->ID()->getText());
        std::vector<Value*> args;
        for (int arg = 0; arg < ctx->funParams()->expr().size(); arg++) {
          args.push_back(std::any_cast<Value*>(visitExpr(ctx->funParams()->expr()[arg])));
        }

        if (fun->getReturnType() != voidType) {
          return (Value*)builder->CreateCall(fun, args);
        } else {
          builder->CreateCall(fun, args);
          return nullptr;
        }
      }
    } else if (ctx->TERN_OP()) {
      return (Value*) builder->CreateSelect(
        std::any_cast<Value*>(visitExpr(ctx->expr()[0])),
        std::any_cast<Value*>(visitExpr(ctx->expr()[1])),
        std::any_cast<Value*>(visitExpr(ctx->expr()[2]))
      );
    } else if (ctx->BIN_OP()) {
      std::string op = ctx->BIN_OP()->getText();
      Value* arg0 = std::any_cast<Value*>(visitExpr(ctx->expr()[0]));
      Value* arg1 = std::any_cast<Value*>(visitExpr(ctx->expr()[1]));
      if (op == "==") {
        return (Value*) builder->CreateICmpEQ(arg0, arg1);
      } else if (op == "!=") {
        return (Value*) builder->CreateICmpNE(arg0, arg1);
      } else if (op == "||") {
        return (Value*) builder->CreateLogicalOr(arg0, arg1);
      } else if (op == "|") {
        return builder->CreateOr(arg0, arg1);
      } else if (op == "&&") {
        return builder->CreateLogicalAnd(arg0, arg1);
      } else if (op == "&") {
        return builder->CreateAnd(arg0, arg1);
      } else if (op == "*") {
        return builder->CreateMul(arg0, arg1);
      } else if (op == "+") {
        return builder->CreateAdd(arg0, arg1);
      } else if (op == "%") {
        return builder->CreateSRem(arg0, arg1);
      } else if (op == "/") {
        return builder->CreateSDiv(arg0, arg1);
      }
    } else if (ctx->INT()) {
      return (Value *)builder->getInt32(std::stoi(ctx->INT()->getText()));
    }
    
    return nullptr;
  }

  Value *registerVar(const std::string &name, Value *val, bool isPHI = false) {
    vars.back()[name] = {isPHI, val};
    return val;
  }

  std::pair<bool, Value*> searchVar(const std::string &name) {
    for (auto it = vars.rbegin(); it != vars.rend(); ++it) {
      if (auto find = it->find(name); find != it->end()) {
        return find->second;
      }
    }
    return {false, nullptr};
  }
};

int main(int argc, const char *argv[]) {
  if (argc != 2 && argc != 3) {
    outs() << "[ERROR] Need arguments: file with PDDLang and optional output "
              "file for LLVM IR\n";
    return 1;
  }
  bool interpretMode = (argc == 2);

  std::ifstream stream;
  stream.open(argv[1]);
  antlr4::ANTLRInputStream input(stream);
  GrammarLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  GrammarParser parser(&tokens);

  LLVMContext context;
  Module *module = new Module("top", context);
  IRBuilder<> builder(context);

  TreeLLVMWalker walker(&context, &builder, module, interpretMode);
  walker.visitProgram(parser.program());

  outs() << "[LLVM IR]\n";
  module->print(outs(), nullptr);
  outs() << '\n';
  bool verif = verifyModule(*module, &outs());
  outs() << "[VERIFICATION] " << (verif ? "FAIL\n\n" : "OK\n\n");

  Function *appFunc = module->getFunction("app");
  if (appFunc == nullptr) {
    outs() << "Can't find app function\n";
    return -1;
  }

  if (interpretMode) {
    outs() << "[EE] Run\n";
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    ExecutionEngine *ee =
        EngineBuilder(std::unique_ptr<Module>(module)).create();
    ee->InstallLazyFunctionCreator([](const std::string &fnName) -> void * {
      if (fnName == "putPixel") {
        return reinterpret_cast<void *>(simPutPixel);
      }
      if (fnName == "flush") {
        return reinterpret_cast<void *>(simFlush);
      }
      if (fnName == "rand") {
        return reinterpret_cast<void *>(simRand);
      }
      if (fnName == "memset") {
        return reinterpret_cast<void *>(memset);
      }
      outs() << "[ExecutionEngine] Can't find function " << fnName
             << "\n";
      return nullptr;
    });
    ee->finalizeObject();

    simInit();

    ArrayRef<GenericValue> noargs;
    GenericValue v = ee->runFunction(appFunc, noargs);
    outs() << "[END]\n";

    simExit();
  } else {
    outs() << "[OUTPUT] " << argv[2] << "\n";
    std::error_code EC;
    raw_fd_ostream OutputFile(argv[2], EC);
    if (!EC) {
      module->print(OutputFile, nullptr);
    }
  }

  return 0;
}