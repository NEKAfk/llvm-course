#include "../include/fullIR.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <vector>

using namespace llvm;

void FullIR::buildIR(Binary &Bin) {
  module = new Module("top", context);
  IRBuilder<> builder(context);
  voidType = Type::getVoidTy(context);
  int32Type = Type::getInt32Ty(context);
  int32PtrType = Type::getInt32Ty(context)->getPointerTo();
  int64Type = Type::getInt64Ty(context);
  int64PtrType = Type::getInt64Ty(context)->getPointerTo();
  Type *boolType = Type::getInt1Ty(context);

  FunctionType *funcType = FunctionType::get(voidType, false);
  mainFunc =
      Function::Create(funcType, Function::ExternalLinkage, "app", module);

  FunctionType *voidFuncType = FunctionType::get(voidType, false);
  ArrayRef<Type *> int32x3Types = {int32Type, int32Type, int32Type};
  FunctionType *int32x3FuncType =
      FunctionType::get(voidType, int32x3Types, false);

  FunctionCallee simPutPixelFunc =
      module->getOrInsertFunction("simPutPixel", int32x3FuncType);

  FunctionType *simFlushType = FunctionType::get(voidType, false);
  FunctionCallee simFlushFunc =
      module->getOrInsertFunction("simFlush", simFlushType);

  FunctionType *simRandType = FunctionType::get(int32Type, false);
  FunctionCallee simRandFunc =
      module->getOrInsertFunction("simRand", simRandType);

  std::unordered_map<uint32_t, BasicBlock *> BBMap;
  for (auto &BB : Bin.BBName2PC) {
    BBMap[BB.second] = BasicBlock::Create(context, BB.first, mainFunc);
  }

  uint32_t PC = 0;
  builder.SetInsertPoint(BBMap[0]);

  ArrayType *regFileType = ArrayType::get(int64Type, CPU::RegSize);
  Value *regFile = builder.CreateAlloca(regFileType);

  ArrayType *stackType = ArrayType::get(builder.getInt8Ty(), CPU::StackSize);
  Value *stack = builder.CreateAlloca(stackType);

  builder.CreateStore(builder.CreateConstGEP2_32(stackType, stack, 0, CPU::StackSize / 4), builder.CreateConstGEP2_64(regFileType, regFile, 0, 0));

  for (Instr &I : Bin.Instrs) {
    switch (I.Op) {
    default:
      break;
#define ISA_(Opcode_, Name_, SkipArgs_, ReadArgs_, WriteArgs_, Execute_,       \
             IRGenExecute_)                                                    \
  case (Opcode_):                                                              \
    IRGenExecute_;                                                             \
    break;
#include "../include/ISA.h"
#undef ISA_
    }
    PC++;
    auto BB = BBMap.find(PC);
    if (BB != BBMap.end()) {
      builder.CreateBr(BB->second);
      builder.SetInsertPoint(BB->second);
    }
  }
}

void FullIR::executeIR(CPU &Cpu) {
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  ee->InstallLazyFunctionCreator([](const std::string &fnName) -> void * {
    if (fnName == "simFlush") {
      return reinterpret_cast<void *>(simFlush);
    }
    if (fnName == "simRand") {
      return reinterpret_cast<void *>(simRand);
    }
    if (fnName == "simPutPixel") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    return nullptr;
  });
  ee->finalizeObject();

  simInit();
  CPU::setCPU(&Cpu);
  Cpu.DumpInstrs = true;

  ArrayRef<GenericValue> noargs;
  outs() << "\n#[Running code]\n";
  ee->runFunction(mainFunc, noargs);
  outs() << "#[Code was run]\n";

  simExit();
}
