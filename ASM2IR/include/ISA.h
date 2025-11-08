// ISA format:
// Opcode
// Name
// SkipArgs: string -> 0 [ifstream InputFile]
// ReadArgs: string -> args [ifstream InputFile, Instr I, map BBName2PC]
// WriteArgs: args -> string [stringstream Stream, Instr I, map PC2BBName]
// Execute: args -> EXECUTION [uint64_t R1, uint64_t R2, uint64_t R3Imm, uint64_t R4Imm, uint64_t R5Imm, CPU *C]
// IRGenExecute = args -> IR [IRBuilder builder, regFileType regFile, Instr I,
//                            map BBMap, uint32_t PC, GraphicalFuncs]

// ISA_(Opcode_, Name_, SkipArgs_, ReadArgs_, WriteArgs_, Execute_,
// IRGenExecute_)

// SkipArgs
#define SKIP_5ARGS                                                             \
  { InputFile >> Arg >> Arg >> Arg >> Arg >> Arg; }
#define SKIP_4ARGS                                                             \
  { InputFile >> Arg >> Arg >> Arg >> Arg; }
#define SKIP_3ARGS                                                             \
  { InputFile >> Arg >> Arg >> Arg; }
#define SKIP_2ARGS                                                             \
  { InputFile >> Arg >> Arg; }
#define SKIP_1ARGS                                                             \
  { InputFile >> Arg; }

// ReadArgs
#define READ_REG(Reg)                                                          \
  {                                                                            \
    InputFile >> Arg;                                                          \
    I.Reg = std::stoi(Arg.substr(1));                                          \
  }
#define READ_IMM(Imm)                                                          \
  {                                                                            \
    InputFile >> Arg;                                                          \
    I.Imm = std::stoi(Arg);                                                  \
  }
#define READ_LABEL(Imm)                                                        \
  {                                                                            \
    InputFile >> Arg;    \
    if (BBName2PC.find(Arg) == BBName2PC.end()) {                              \
      ErrorMsg = std::string("Can't find label: " + Arg);                      \
      return true;                                                             \
    }                                                                          \
    I.Imm = BBName2PC[Arg];                                                  \
  }
#define READ_2REGS_IMM_2REGS                                                             \
  { READ_REG(R1) READ_REG(R2) READ_IMM(R5Imm) READ_REG(R3Imm) READ_REG(R4Imm)}
#define READ_3REGS                                                             \
  { READ_REG(R1) READ_REG(R2) READ_REG(R3Imm) }
#define READ_3REGS_IMM                                                        \
  { READ_REG(R1) READ_REG(R2) READ_REG(R3Imm) READ_IMM(R4Imm) }
#define READ_2REGS_2IMM                                                        \
  { READ_REG(R1) READ_REG(R2) READ_IMM(R3Imm) READ_IMM(R4Imm) }
#define READ_2REGS_IMM                                                         \
  { READ_REG(R1) READ_REG(R2) READ_IMM(R3Imm) }
#define READ_2REGS                                                             \
  { READ_REG(R1) READ_REG(R2) }
#define READ_REG_LABEL                                                         \
  { READ_REG(R1) READ_LABEL(R3Imm) }
#define READ_REG_2LABELS                                                         \
  { READ_REG(R1) READ_LABEL(R3Imm) READ_LABEL(R4Imm) }
#define READ_REG_IMM_2LABELS                                                             \
  { READ_REG(R1) READ_IMM(R4Imm) READ_LABEL(R2) READ_LABEL(R3Imm)}
#define READ_REG_IMM                                                           \
  { READ_REG(R1) READ_IMM(R3Imm) }

// WriteArgs
#define WRITE_REG(Reg)                                                         \
  { Stream << " x" << I.Reg; }
#define WRITE_IMM(Imm)                                                              \
  { Stream << " " << I.Imm; }
#define WRITE_LABEL(Imm)                                                            \
  { Stream << " " << PC2BBName[I.Imm]; }
#define WRITE_2REGS_IMM_2REGS                                                             \
  { WRITE_REG(R1) WRITE_REG(R2) WRITE_IMM(R5Imm) WRITE_REG(R3Imm) WRITE_REG(R4Imm)}
#define WRITE_3REGS                                                            \
  { WRITE_REG(R1) WRITE_REG(R2) WRITE_REG(R3Imm) }
#define WRITE_3REGS_IMM                                                       \
  { WRITE_REG(R1) WRITE_REG(R2) WRITE_REG(R3Imm) WRITE_IMM(R4Imm) }
#define WRITE_2REGS_2IMM                                                       \
  { WRITE_REG(R1) WRITE_REG(R2) WRITE_IMM(R3Imm) WRITE_IMM(R4Imm) }
#define WRITE_2REGS_IMM                                                        \
  { WRITE_REG(R1) WRITE_REG(R2) WRITE_IMM(R3Imm) }
#define WRITE_2REGS                                                            \
  { WRITE_REG(R1) WRITE_REG(R2) }
#define WRITE_REG_LABEL                                                        \
  { WRITE_REG(R1) WRITE_LABEL(R3Imm) }
#define WRITE_REG_2LABEL                                                        \
  { WRITE_REG(R1) WRITE_LABEL(R3Imm) WRITE_LABEL(R4Imm) }
#define WRITE_REG_IMM_2LABELS                                                             \
  { WRITE_REG(R1) WRITE_IMM(R4Imm) WRITE_LABEL(R2) WRITE_LABEL(R3Imm)}
#define WRITE_REG_IMM                                                          \
  { WRITE_REG(R1) WRITE_IMM(R3Imm) }

// IRGenExecute_
#define GEP2_64(Arg) builder.CreateConstGEP2_64(regFileType, regFile, 0, Arg)
#define LOAD_PTR(Arg) builder.CreateLoad(int32PtrType, GEP2_64(Arg))
#define LOAD_REG(Arg) builder.CreateLoad(int64Type, GEP2_64(Arg))
#define GEN_IMM(Arg) builder.getInt64(Arg)
#define GEN_BYTE(Arg) builder.getInt8(Arg)

// ISA_(Opcode_, Name_, SkipArgs_, ReadArgs_, WriteArgs_, Execute_,
// IRGenExecute_)

ISA_(
    0xFF, FLUSH, {}, {}, {}, { simFlush(); },
    { builder.CreateCall(simFlushFunc); })

ISA_(
    0x01, ZEROES, SKIP_2ARGS, READ_REG_IMM, WRITE_REG_IMM,
    { std::memset((void*)C->RegFile[R1], 0, R3Imm);},
    {
      builder.CreateMemSet(LOAD_PTR(I.R1), GEN_BYTE(0), GEN_IMM(I.R3Imm), llvm::MaybeAlign{});
    })

ISA_(
    0x02, ADD, SKIP_3ARGS, READ_3REGS, WRITE_3REGS,
    { C->RegFile[R1] = C->RegFile[R2] + C->RegFile[R3Imm]; },
    {
      builder.CreateStore(builder.CreateAdd(LOAD_REG(I.R2), LOAD_REG(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x03, ADDi, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] + R3Imm; },
    {
      builder.CreateStore(builder.CreateAdd(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x04, MOV, SKIP_2ARGS, READ_2REGS, WRITE_2REGS,
    { C->RegFile[R1] = C->RegFile[R2]; },
    {
      builder.CreateStore(LOAD_REG(I.R2),
                          GEP2_64(I.R1));
    })

ISA_(
    0x05, MOVi, SKIP_2ARGS, READ_REG_IMM, WRITE_REG_IMM,
    { C->RegFile[R1] = R3Imm; },
    {
      builder.CreateStore(GEN_IMM(I.R3Imm),
                          GEP2_64(I.R1));
    })

ISA_(
    0x06, MULi, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] * R3Imm; },
    {
      builder.CreateStore(builder.CreateMul(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x07, XOR, SKIP_3ARGS, READ_3REGS, WRITE_3REGS,
    { C->RegFile[R1] = C->RegFile[R2] ^ C->RegFile[R3Imm]; },
    {
      builder.CreateStore(builder.CreateXor(LOAD_REG(I.R2), LOAD_REG(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x08, XORi, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] ^ R3Imm; },
    {
      builder.CreateStore(builder.CreateXor(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x09, SUBi, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] - R3Imm; },
    {
      builder.CreateStore(builder.CreateSub(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x0a, ICMP_EQ, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] == R3Imm ? 1 : 0; },
    {
      builder.CreateStore(builder.CreateICmpEQ(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x0b, ICMP_NE, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] != R3Imm ? 1 : 0; },
    {
      builder.CreateStore(builder.CreateICmpNE(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x0c, RND_MOD, SKIP_2ARGS, READ_REG_IMM, WRITE_REG_IMM, 
    { C->RegFile[R1] = simRand() % R3Imm; },
    { builder.CreateStore(
        builder.CreateURem(
          builder.CreateZExt(
            builder.CreateCall(simRandFunc), 
            int64Type),
          GEN_IMM(I.R3Imm)), 
        GEP2_64(I.R1)); 
    })

ISA_(
    0x0e, SELECTii, SKIP_4ARGS, READ_2REGS_2IMM, WRITE_2REGS_2IMM,
    { C->RegFile[R1] = C->RegFile[R2] ? R3Imm : R4Imm; },
    {
      builder.CreateStore(builder.CreateSelect(builder.CreateTrunc(LOAD_REG(I.R2), builder.getInt1Ty()), 
                                                GEN_IMM(I.R3Imm), GEN_IMM(I.R4Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x0f, SELECTri, SKIP_4ARGS, READ_3REGS_IMM, WRITE_3REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] ? C->RegFile[R3Imm] : R4Imm; },
    {
      builder.CreateStore(builder.CreateSelect(builder.CreateTrunc(LOAD_REG(I.R2), builder.getInt1Ty()), 
                                              LOAD_REG(I.R3Imm), GEN_IMM(I.R4Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x10, PUT_PIXEL, SKIP_3ARGS, READ_3REGS, WRITE_3REGS,
    { simPutPixel(C->RegFile[R1], C->RegFile[R2], C->RegFile[R3Imm]); },
    {
      builder.CreateCall(simPutPixelFunc,
                         {builder.CreateTrunc(LOAD_REG(I.R1), int32Type), 
                          builder.CreateTrunc(LOAD_REG(I.R2), int32Type),
                          builder.CreateTrunc(LOAD_REG(I.R3Imm), int32Type)});
    })

ISA_(
    0x11, STORE, SKIP_2ARGS, READ_2REGS, WRITE_2REGS,
    { *((int32_t*)C->RegFile[R2]) = C->RegFile[R1]; },
    {
      builder.CreateStore(builder.CreateTrunc(LOAD_REG(I.R1), int32Type), LOAD_PTR(I.R2));
    })

ISA_(
    0x12, LOAD, SKIP_2ARGS, READ_2REGS, WRITE_2REGS,
    { C->RegFile[R1] = *((int32_t*)C->RegFile[R2]); },
    {
      builder.CreateStore(builder.CreateZExt(builder.CreateLoad(int32Type, LOAD_PTR(I.R1)), int64Type), GEP2_64(I.R1));
    })


ISA_(
    0x13, SHLi, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] << R3Imm; },
    {
      builder.CreateStore(builder.CreateShl(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x14, OR, SKIP_3ARGS, READ_3REGS, WRITE_3REGS,
    { C->RegFile[R1] = C->RegFile[R2] | C->RegFile[R3Imm]; },
    {
      builder.CreateStore(builder.CreateOr(LOAD_REG(I.R2), LOAD_REG(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x15, JMP_COND, SKIP_3ARGS, READ_REG_2LABELS, WRITE_REG_2LABEL,
    {
      if (C->RegFile[R1]) {
        C->NextPC = R3Imm;
      } else {
        C->NextPC = R4Imm;
      }
    },
    {
      PC++;
      builder.CreateCondBr(
          builder.CreateTrunc(LOAD_REG(I.R1), builder.getInt1Ty()),
          BBMap[I.R3Imm], BBMap[I.R4Imm]);
      builder.SetInsertPoint(BBMap[PC]);
      continue;
    })

ISA_(
    0x16, JMP, SKIP_1ARGS, READ_LABEL(R3Imm), WRITE_LABEL(R3Imm), { C->NextPC = R3Imm; },
    {
      PC++;
      builder.CreateBr(BBMap[I.R3Imm]);
      builder.SetInsertPoint(BBMap[PC]);
      continue;
    })

ISA_(
    0x17, ANDi, SKIP_3ARGS, READ_2REGS_IMM, WRITE_2REGS_IMM,
    { C->RegFile[R1] = C->RegFile[R2] & R3Imm; },
    {
      builder.CreateStore(builder.CreateAnd(LOAD_REG(I.R2), GEN_IMM(I.R3Imm)),
                          GEP2_64(I.R1));
    })

ISA_(
    0x18, GEP32, SKIP_3ARGS, READ_3REGS, WRITE_3REGS,
    { C->RegFile[R1] = (int64_t) (((int32_t*)C->RegFile[R2]) + C->RegFile[R3Imm]); },
    {
      builder.CreateStore(builder.CreateGEP(int32Type, LOAD_PTR(I.R2), {LOAD_REG(I.R3Imm), }),
                          GEP2_64(I.R1));
    })

ISA_(
    0x19, GEP2_32, SKIP_5ARGS, READ_2REGS_IMM_2REGS, WRITE_2REGS_IMM_2REGS,
    { C->RegFile[R1] = (int64_t) (((int32_t*)C->RegFile[R2]) + C->RegFile[R3Imm] * R5Imm + C->RegFile[R4Imm]); },
    {
      builder.CreateStore(builder.CreateGEP(int32Type, LOAD_PTR(I.R2), 
            {builder.CreateAdd(builder.CreateMul(LOAD_REG(I.R3Imm), GEN_IMM(I.R5Imm)), LOAD_REG(I.R4Imm)), }),
                          GEP2_64(I.R1));
    })

ISA_(
    0x1a, JMP_EQ, SKIP_4ARGS, READ_REG_IMM_2LABELS, WRITE_REG_IMM_2LABELS,
    {
      if (C->RegFile[R1] == R4Imm) {
        C->NextPC = R2;
      } else {
        C->NextPC = R3Imm;
      }
    },
    {
      PC++;
      builder.CreateCondBr(
          builder.CreateICmpEQ(LOAD_REG(I.R1), GEN_IMM(I.R4Imm)),
          BBMap[I.R2], BBMap[I.R3Imm]);
      builder.SetInsertPoint(BBMap[PC]);
      continue;
    })