#ifndef CPU_H
#define CPU_H
#include "sim.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ios>

struct CPU {
  static constexpr uint32_t RegSize = 16;
  static constexpr uint32_t StackSize = 100000;
  char Stack[StackSize];
  int64_t RegFile[RegSize] = {(int64_t) (Stack + StackSize)};
  uint32_t PC;
  uint32_t NextPC;
  uint32_t Run;
  bool DumpInstrs = false;

  bool Execute(Binary &Bin, std::string &ErrorMsg);
  std::string dumpStatus(Binary &Bin);

  static CPU *C;
  static void setCPU(CPU *Cpu) { 
    C = Cpu; 
  }
#define ISA_(Opcode_, Name_, SkipArgs_, ReadArgs_, WriteArgs_, Execute_,           \
             IRGenExecute_)                                                        \
  static void do_##Name_(int64_t R1, int64_t R2, int64_t R3Imm, int64_t R4Imm, int64_t R5Imm) {   \
    if (C->DumpInstrs)                                                             \
      std::cout << #Name_ "\n";     \
    Execute_;                                                                      \
  }
#include "ISA.h"
#undef ISA_
};
#endif // CPU_H
