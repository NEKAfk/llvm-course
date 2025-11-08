#include "../include/extIR.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <memory>
#include <unordered_map>
#include <string>

using namespace llvm;

void ExtIR::buildIR(Binary &Bin) {
  module = new Module("top", context);
  IRBuilder<> builder(context);
  voidType = Type::getVoidTy(context);
  int32Type = Type::getInt32Ty(context);
  int32PtrType = Type::getInt32Ty(context)->getPointerTo();
  int64Type = Type::getInt64Ty(context);
  int64PtrType = Type::getInt64Ty(context)->getPointerTo();

  ArrayType *regFileType = ArrayType::get(int64Type, CPU::RegSize);
  module->getOrInsertGlobal("regFile", regFileType);
  regFile = module->getNamedGlobal("regFile");

  FunctionType *funcType = FunctionType::get(voidType, false);
  mainFunc =
      Function::Create(funcType, Function::ExternalLinkage, "main", module);

  FunctionType *voidFuncType = FunctionType::get(voidType, false);
  ArrayRef<Type *> int64x5Types = {int64Type, int64Type, int64Type, int64Type, int64Type};
  FunctionType *int64x5FuncType =
      FunctionType::get(voidType, int64x5Types, false);

#define ISA_(Opcode_, Name_, SkipArgs_, ReadArgs_, WriteArgs_, Execute_,       \
             IRGenExecute_)                                                    \
  FunctionCallee Callee##Name_ =                                               \
      module->getOrInsertFunction("do_" #Name_, int64x5FuncType);
#include "../include/ISA.h"
#undef ISA_

  std::unordered_map<uint32_t, BasicBlock *> BBMap;
  for (auto &BB : Bin.BBName2PC) {
    BBMap[BB.second] = BasicBlock::Create(context, BB.first, mainFunc);
  }

  uint32_t PC = 0;
  builder.SetInsertPoint(BBMap[0]);
  for (Instr &I : Bin.Instrs) {
    Value *arg1 = builder.getInt64(I.R1);
    Value *arg2 = builder.getInt64(I.R2);
    Value *arg3 = builder.getInt64(I.R3Imm);
    Value *arg4 = builder.getInt64(I.R4Imm);
    Value *arg5 = builder.getInt64(I.R5Imm);
    Value *args[] = {arg1, arg2, arg3, arg4, arg5};
    switch (I.Op) {
    default:
      break;
#define ISA_(Opcode_, Name_, SkipArgs_, ReadArgs_, WriteArgs_, Execute_,       \
             IRGenExecute_)                                                    \
  case (Opcode_):                                                              \
    builder.CreateCall(Callee##Name_, args);                                   \
    break;
#include "../include/ISA.h"
#undef ISA_
    }
    PC++;
    auto BB = BBMap.find(PC);

    switch (I.Op) {
    default:
      if (BB != BBMap.end()) {
        builder.CreateBr(BB->second);
      }
      break;
    case Instr::JMP_COND:
      arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0, I.R1);
      arg2 = builder.CreateTrunc(builder.CreateLoad(int64Type, arg1),
                                 builder.getInt1Ty());
      builder.CreateCondBr(arg2, BBMap[I.R3Imm], BBMap[I.R4Imm]);
      break;
    case Instr::JMP_EQ:
      arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0, I.R1);
      arg2 = builder.getInt64(I.R4Imm);
      arg3 = builder.CreateICmpEQ(builder.CreateLoad(int64Type, arg1), arg2);
      builder.CreateCondBr(arg3, BBMap[I.R2], BBMap[I.R3Imm]);
      break;
    case Instr::JMP:
      builder.CreateBr(BBMap[I.R3Imm]);
      break;
    }
    if (BB != BBMap.end()) {
      builder.SetInsertPoint(BB->second);
    }
  }
}

void ExtIR::dumpIR() {
  outs() << "\n[LLVM IR]:\n";
  module->print(outs(), nullptr);
  outs() << '\n';
}
bool ExtIR::verifyIR() {
  bool verif = verifyFunction(*mainFunc, &outs());
  outs() << "[VERIFICATION] " << (verif ? "FAIL\n\n" : "OK\n\n");
  return verif;
}

void ExtIR::executeIR(CPU &Cpu) {
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  ee->InstallLazyFunctionCreator([](const std::string &fnName) -> void * {
#define ISA_(Opcode_, Name_, SkipArgs_, ReadArgs_, WriteArgs_, Execute_,       \
             IRGenExecute_)                                                    \
  if (fnName == "do_" #Name_)                                                  \
    return reinterpret_cast<void *>(CPU::do_##Name_);
#include "../include/ISA.h"
#undef ISA_
    return nullptr;
  });

  ee->addGlobalMapping(regFile, (void *)Cpu.RegFile);
  ee->finalizeObject();

  simInit();
  CPU::setCPU(&Cpu);

  ArrayRef<GenericValue> noargs;
  outs() << "\n#[Running code]\n";
  ee->runFunction(mainFunc, noargs);
  outs() << "#[Code was run]\n";

  simExit();
}
