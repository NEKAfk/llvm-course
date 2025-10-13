#include "../SDL/include/sim.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

int main() {
	using namespace llvm;

	LLVMContext context;
	Module module("some_cool_module_name", context);
	IRBuilder builder(context);
	Type *Int1Type = Type::getInt1Ty(context);
	Type *Int1PtrType = Int1Type->getPointerTo();
	Type *Int8Type = Type::getInt8Ty(context);
	Type *Int8PtrType = Int8Type->getPointerTo();
	Type *Int32Type = Type::getInt32Ty(context);
	Type *Int32PtrType = Int32Type->getPointerTo();
	Type *Int64Type = Type::getInt64Ty(context);
	Type *Int64PtrType = Int64Type->getPointerTo();
	Type *VoidType = Type::getVoidTy(context);
	Type *VoidPtrType = VoidType->getPointerTo();

	ArrayRef<Type*> appParamTypes = {};
	FunctionType *appType = FunctionType::get(VoidType, appParamTypes, false);
	llvm::AttributeList appAttributes;
	appAttributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(37));
	appAttributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(42));
	appAttributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(96));

	Function *appFunc = Function::Create(appType, Function::ExternalLinkage, "app", &module);
	appFunc->setAttributes(appAttributes);

	ArrayRef<Type*> llvm_lifetime_start_p0ParamTypes = {Int64Type, Int1PtrType, };
	FunctionType *llvm_lifetime_start_p0Type = FunctionType::get(VoidType, llvm_lifetime_start_p0ParamTypes, false);
	llvm::AttributeList llvm_lifetime_start_p0Attributes;
	llvm_lifetime_start_p0Attributes.addParamAttribute(context, 0, static_cast<llvm::Attribute::AttrKind>(15));
	llvm_lifetime_start_p0Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(25));
	llvm_lifetime_start_p0Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(30));
	llvm_lifetime_start_p0Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(40));
	llvm_lifetime_start_p0Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(42));
	llvm_lifetime_start_p0Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(77));
	llvm_lifetime_start_p0Attributes.addParamAttribute(context, 1, static_cast<llvm::Attribute::AttrKind>(90));
	llvm_lifetime_start_p0Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(93));

	FunctionCallee llvm_lifetime_start_p0Func = module.getOrInsertFunction("llvm.lifetime.start.p0", llvm_lifetime_start_p0Type, llvm_lifetime_start_p0Attributes);

	ArrayRef<Type*> llvm_memset_p0_i64ParamTypes = {Int1PtrType, Int8Type, Int64Type, Int1Type, };
	FunctionType *llvm_memset_p0_i64Type = FunctionType::get(VoidType, llvm_memset_p0_i64ParamTypes, false);
	llvm::AttributeList llvm_memset_p0_i64Attributes;
	llvm_memset_p0_i64Attributes.addParamAttribute(context, 3, static_cast<llvm::Attribute::AttrKind>(15));
	llvm_memset_p0_i64Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(25));
	llvm_memset_p0_i64Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(30));
	llvm_memset_p0_i64Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(42));
	llvm_memset_p0_i64Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(77));
	llvm_memset_p0_i64Attributes.addParamAttribute(context, 0, static_cast<llvm::Attribute::AttrKind>(79));
	llvm_memset_p0_i64Attributes.addParamAttribute(context, 0, static_cast<llvm::Attribute::AttrKind>(90));
	llvm_memset_p0_i64Attributes.addFnAttribute(context, static_cast<llvm::Attribute::AttrKind>(93));

	FunctionCallee llvm_memset_p0_i64Func = module.getOrInsertFunction("llvm.memset.p0.i64", llvm_memset_p0_i64Type, llvm_memset_p0_i64Attributes);

	ArrayRef<Type*> simRandParamTypes = {};
	FunctionType *simRandType = FunctionType::get(Int32Type, simRandParamTypes, false);
	llvm::AttributeList simRandAttributes;

	FunctionCallee simRandFunc = module.getOrInsertFunction("simRand", simRandType, simRandAttributes);

	ArrayRef<Type*> simPutPixelParamTypes = {Int32Type, Int32Type, Int32Type, };
	FunctionType *simPutPixelType = FunctionType::get(VoidType, simPutPixelParamTypes, false);
	llvm::AttributeList simPutPixelAttributes;
	simPutPixelAttributes.addParamAttribute(context, 0, static_cast<llvm::Attribute::AttrKind>(41));
	simPutPixelAttributes.addParamAttribute(context, 1, static_cast<llvm::Attribute::AttrKind>(41));
	simPutPixelAttributes.addParamAttribute(context, 2, static_cast<llvm::Attribute::AttrKind>(41));

	FunctionCallee simPutPixelFunc = module.getOrInsertFunction("simPutPixel", simPutPixelType, simPutPixelAttributes);

	ArrayRef<Type*> simFlushParamTypes = {};
	FunctionType *simFlushType = FunctionType::get(VoidType, simFlushParamTypes, false);
	llvm::AttributeList simFlushAttributes;

	FunctionCallee simFlushFunc = module.getOrInsertFunction("simFlush", simFlushType, simFlushAttributes);

	BasicBlock *BB0= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB1= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB2= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB3= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB4= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB5= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB6= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB7= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB8= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB9= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB10= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB11= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB12= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB13= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB14= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB15= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB16= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB17= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB18= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB19= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB20= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB21= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB22= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB23= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB24= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB25= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB26= BasicBlock::Create(context, "", appFunc);
	BasicBlock *BB27= BasicBlock::Create(context, "", appFunc);

	builder.SetInsertPoint(BB0);

	builder.SetInsertPoint(BB1);
	Value *I0 = builder.CreatePHI(Int64Type, 2);

	builder.SetInsertPoint(BB2);

	builder.SetInsertPoint(BB3);
	Value *I1 = builder.CreatePHI(Int64Type, 2);

	builder.SetInsertPoint(BB4);

	builder.SetInsertPoint(BB5);
	Value *I2 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB6);
	Value *I3 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB7);
	Value *I4 = builder.CreatePHI(Int64Type, 2);

	builder.SetInsertPoint(BB8);

	builder.SetInsertPoint(BB9);

	builder.SetInsertPoint(BB10);
	Value *I5 = builder.CreatePHI(Int64Type, 2);

	builder.SetInsertPoint(BB11);
	Value *I6 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB12);

	builder.SetInsertPoint(BB13);
	Value *I7 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB14);

	builder.SetInsertPoint(BB15);
	Value *I8 = builder.CreatePHI(Int64Type, 2);

	builder.SetInsertPoint(BB16);

	builder.SetInsertPoint(BB17);
	Value *I9 = builder.CreatePHI(Int64Type, 2);

	builder.SetInsertPoint(BB18);

	builder.SetInsertPoint(BB19);
	Value *I10 = builder.CreatePHI(Int32Type, 2);
	Value *I11 = builder.CreatePHI(Int32Type, 2);
	Value *I12 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB20);

	builder.SetInsertPoint(BB21);

	builder.SetInsertPoint(BB22);
	Value *I13 = builder.CreatePHI(Int32Type, 2);
	Value *I14 = builder.CreatePHI(Int32Type, 2);
	Value *I15 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB23);

	builder.SetInsertPoint(BB24);
	Value *I16 = builder.CreatePHI(Int32Type, 2);
	Value *I17 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB25);

	builder.SetInsertPoint(BB26);

	builder.SetInsertPoint(BB27);
	Value *I18 = builder.CreatePHI(Int32Type, 2);

	builder.SetInsertPoint(BB24);
	Value *I19 = builder.CreateAdd(I13, builder.getInt32(1), "", false, true);
	Value *I20 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I19, builder.getInt32(2));
	builder.CreateCondBr(I20, BB21, BB22);

	builder.SetInsertPoint(BB26);
	Value *I21 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I17, builder.getInt32(0));
	Value *I22 = builder.CreateSelect(I21, builder.getInt32(65280), builder.getInt32(16711680));
	builder.CreateBr(BB27);

	builder.SetInsertPoint(BB22);
	Value *I23 = builder.CreateOr(I13, I10);
	Value *I24 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I23, builder.getInt32(0));
	builder.CreateCondBr(I24, BB24, BB23);

	builder.SetInsertPoint(BB21);
	Value *I25 = builder.CreateAdd(I10, builder.getInt32(1), "", false, true);
	Value *I26 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I25, builder.getInt32(2));
	builder.CreateCondBr(I26, BB20, BB19);

	builder.SetInsertPoint(BB17);
	Value *I27 = builder.CreateTrunc(I9, Int32Type, "", true, true);
	builder.CreateBr(BB19);

	builder.SetInsertPoint(BB18);
	Value *I28 = builder.CreateAdd(I8, builder.getInt64(1), "", true, true);
	Value *I29 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I28, builder.getInt64(33));
	builder.CreateCondBr(I29, BB16, BB15);

	builder.SetInsertPoint(BB15);
	Value *I30 = builder.CreateMul(I8, builder.getInt64(66), "", true, true);
	Value *I31 = builder.CreateTrunc(I8, Int32Type, "", true, true);
	builder.CreateBr(BB17);

	builder.SetInsertPoint(BB20);
	Value *I32 = builder.CreateAdd(I9, I30, "", true, true);
	Value *I33 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I16, builder.getInt32(3));
	builder.CreateCondBr(I33, BB26, BB25);

	builder.SetInsertPoint(BB19);
	Value *I34 = builder.CreateAdd(I10, I31, "", false, true);
	Value *I35 = builder.CreateMul(I34, builder.getInt32(66), "", true, true);
	Value *I36 = builder.CreateAdd(I35, I27, "", true, true);
	builder.CreateBr(BB22);

	builder.SetInsertPoint(BB12);
	Value *I37 = builder.CreateAdd(I6, builder.getInt32(1), "", true, true);
	Value *I38 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I37, builder.getInt32(8));
	builder.CreateCondBr(I38, BB8, BB11);

	builder.SetInsertPoint(BB14);
	builder.CreateCall(simFlushFunc, {});
	Value *I39 = builder.CreateXor(I3, builder.getInt32(1));
	Value *I40 = builder.CreateZExt(I39, Int64Type, "", true);
	builder.CreateBr(BB15);

	builder.SetInsertPoint(BB16);
	Value *I41 = builder.CreateAnd(I3, builder.getInt32(1));
	Value *I42 = builder.CreateXor(I41, builder.getInt32(1));
	builder.CreateBr(BB6);

	builder.SetInsertPoint(BB4);
	Value *I43 = builder.CreateCall(simRandFunc, {});
	Value *I44 = builder.CreateSRem(I43, builder.getInt32(50));
	Value *I45 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I44, builder.getInt32(0));
	Value *I46 = builder.CreateSelect(I45, builder.getInt32(16711680), builder.getInt32(65280));
	builder.CreateBr(BB5);

	builder.SetInsertPoint(BB3);
	Value *I47 = builder.CreateCall(simRandFunc, {});
	Value *I48 = builder.CreateSRem(I47, builder.getInt32(10));
	Value *I49 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I48, builder.getInt32(0));
	builder.CreateCondBr(I49, BB4, BB5);

	builder.SetInsertPoint(BB2);
	Value *I50 = builder.CreateAdd(I0, builder.getInt64(1), "", true, true);
	Value *I51 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I50, builder.getInt64(33));
	builder.CreateCondBr(I51, BB6, BB1);

	builder.SetInsertPoint(BB0);
	Value *I52 = builder.CreateAlloca(ArrayType::get(ArrayType::get(Int32Type, 2244), 2));
	builder.CreateCall(llvm_lifetime_start_p0Func, {builder.getInt64(17952), I52, });
	builder.CreateCall(llvm_memset_p0_i64Func, {I52, builder.getInt8(0), builder.getInt64(17952), builder.getInt1(0), });
	builder.CreateBr(BB1);

	builder.SetInsertPoint(BB27);
	Value *I53 = builder.CreateGEP(ArrayType::get(ArrayType::get(Int32Type, 2244), 2), I52, {builder.getInt64(0), I40, I32, }, "", GEPNoWrapFlags::fromRaw(7));
	builder.CreateStore(I18, I53);
	Value *I54 = builder.CreateAdd(I9, builder.getInt64(1), "", true, true);
	Value *I55 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I54, builder.getInt64(65));
	builder.CreateCondBr(I55, BB18, BB17);

	builder.SetInsertPoint(BB6);
	Value *I56 = builder.CreateZExt(I3, Int64Type, "", true);
	Value *I57 = builder.CreateGEP(ArrayType::get(ArrayType::get(Int32Type, 2244), 2), I52, {builder.getInt64(0), I56, }, "", GEPNoWrapFlags::fromRaw(7));
	builder.CreateBr(BB7);

	builder.SetInsertPoint(BB23);
	Value *I58 = builder.CreateAdd(I36, I13, "", false, true);
	Value *I59 = builder.CreateZExt(I58, Int64Type, "", false);
	Value *I60 = builder.CreateGEP(ArrayType::get(ArrayType::get(Int32Type, 2244), 2), I52, {builder.getInt64(0), I56, I59, }, "", GEPNoWrapFlags::fromRaw(7));
	Value *I61 = builder.CreateLoad(Int32Type, I60);
	Value *I62 = builder.CreateICmp(CmpInst::Predicate::ICMP_NE, I61, builder.getInt32(0));
	Value *I63 = builder.CreateZExt(I62, Int32Type, "", false);
	Value *I64 = builder.CreateAdd(I15, I63, "", false, false);
	Value *I65 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I61, builder.getInt32(16711680));
	Value *I66 = builder.CreateZExt(I65, Int32Type, "", false);
	Value *I67 = builder.CreateOr(I14, I66);
	builder.CreateBr(BB24);

	builder.SetInsertPoint(BB25);
	Value *I68 = builder.CreateGEP(ArrayType::get(ArrayType::get(Int32Type, 2244), 2), I52, {builder.getInt64(0), I56, I32, }, "", GEPNoWrapFlags::fromRaw(7));
	Value *I69 = builder.CreateLoad(Int32Type, I68);
	Value *I70 = builder.CreateICmp(CmpInst::Predicate::ICMP_NE, I69, builder.getInt32(0));
	Value *I71 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I16, builder.getInt32(2));
	Value *I72 = builder.CreateSelect(I70, I71, builder.getInt1(0));
	builder.CreateCondBr(I72, BB26, BB27);

	builder.SetInsertPoint(BB7);
	Value *I73 = builder.CreateAdd(I4, builder.getInt64(1), "", true, true);
	Value *I74 = builder.CreateGEP(Int32Type, I57, {I73, }, "", GEPNoWrapFlags::fromRaw(7));
	Value *I75 = builder.CreateTrunc(I4, Int32Type, "", false, false);
	Value *I76 = builder.CreateShl(I75, builder.getInt32(3));
	builder.CreateBr(BB10);

	builder.SetInsertPoint(BB11);
	Value *I77 = builder.CreateAdd(I6, I76, "", true, true);
	builder.CreateBr(BB13);

	builder.SetInsertPoint(BB10);
	Value *I78 = builder.CreateAdd(I5, builder.getInt64(1), "", true, true);
	Value *I79 = builder.CreateMul(I78, builder.getInt64(264), "", true, true);
	Value *I80 = builder.CreateGEP(Int8Type, I74, {I79, }, "", GEPNoWrapFlags::fromRaw(7));
	Value *I81 = builder.CreateLoad(Int32Type, I80);
	Value *I82 = builder.CreateTrunc(I5, Int32Type, "", false, false);
	Value *I83 = builder.CreateShl(I82, builder.getInt32(3));
	builder.CreateBr(BB11);

	builder.SetInsertPoint(BB13);
	Value *I84 = builder.CreateAdd(I7, I83, "", true, true);
	builder.CreateCall(simPutPixelFunc, {I77, I84, I81, });
	Value *I85 = builder.CreateAdd(I7, builder.getInt32(1), "", true, true);
	Value *I86 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I85, builder.getInt32(8));
	builder.CreateCondBr(I86, BB12, BB13);

	builder.SetInsertPoint(BB8);
	Value *I87 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I78, builder.getInt64(32));
	builder.CreateCondBr(I87, BB9, BB10);

	builder.SetInsertPoint(BB9);
	Value *I88 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I73, builder.getInt64(64));
	builder.CreateCondBr(I88, BB14, BB7);

	builder.SetInsertPoint(BB1);
	Value *I89 = builder.CreateMul(I0, builder.getInt64(264), "", true, true);
	Value *I90 = builder.CreateGEP(Int8Type, I52, {I89, }, "", GEPNoWrapFlags::fromRaw(7));
	builder.CreateBr(BB3);

	builder.SetInsertPoint(BB5);
	Value *I91 = builder.CreateGEP(Int32Type, I90, {I1, }, "", GEPNoWrapFlags::fromRaw(7));
	builder.CreateStore(I2, I91);
	Value *I92 = builder.CreateAdd(I1, builder.getInt64(1), "", true, true);
	Value *I93 = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, I92, builder.getInt64(65));
	builder.CreateCondBr(I93, BB2, BB3);

	static_cast<PHINode*>(I0)->addIncoming(builder.getInt64(1), BB0);
	static_cast<PHINode*>(I0)->addIncoming(I50, BB2);

	static_cast<PHINode*>(I1)->addIncoming(builder.getInt64(1), BB1);
	static_cast<PHINode*>(I1)->addIncoming(I92, BB5);

	static_cast<PHINode*>(I2)->addIncoming(I46, BB4);
	static_cast<PHINode*>(I2)->addIncoming(builder.getInt32(0), BB3);

	static_cast<PHINode*>(I3)->addIncoming(I42, BB16);
	static_cast<PHINode*>(I3)->addIncoming(builder.getInt32(0), BB2);

	static_cast<PHINode*>(I4)->addIncoming(builder.getInt64(0), BB6);
	static_cast<PHINode*>(I4)->addIncoming(I73, BB9);

	static_cast<PHINode*>(I5)->addIncoming(builder.getInt64(0), BB7);
	static_cast<PHINode*>(I5)->addIncoming(I78, BB8);

	static_cast<PHINode*>(I6)->addIncoming(builder.getInt32(0), BB10);
	static_cast<PHINode*>(I6)->addIncoming(I37, BB12);

	static_cast<PHINode*>(I7)->addIncoming(builder.getInt32(0), BB11);
	static_cast<PHINode*>(I7)->addIncoming(I85, BB13);

	static_cast<PHINode*>(I8)->addIncoming(builder.getInt64(1), BB14);
	static_cast<PHINode*>(I8)->addIncoming(I28, BB18);

	static_cast<PHINode*>(I9)->addIncoming(builder.getInt64(1), BB15);
	static_cast<PHINode*>(I9)->addIncoming(I54, BB27);

	static_cast<PHINode*>(I10)->addIncoming(builder.getInt32(-1), BB17);
	static_cast<PHINode*>(I10)->addIncoming(I25, BB21);

	static_cast<PHINode*>(I11)->addIncoming(builder.getInt32(0), BB17);
	static_cast<PHINode*>(I11)->addIncoming(I17, BB21);

	static_cast<PHINode*>(I12)->addIncoming(builder.getInt32(0), BB17);
	static_cast<PHINode*>(I12)->addIncoming(I16, BB21);

	static_cast<PHINode*>(I13)->addIncoming(builder.getInt32(-1), BB19);
	static_cast<PHINode*>(I13)->addIncoming(I19, BB24);

	static_cast<PHINode*>(I14)->addIncoming(I11, BB19);
	static_cast<PHINode*>(I14)->addIncoming(I17, BB24);

	static_cast<PHINode*>(I15)->addIncoming(I12, BB19);
	static_cast<PHINode*>(I15)->addIncoming(I16, BB24);

	static_cast<PHINode*>(I16)->addIncoming(I15, BB22);
	static_cast<PHINode*>(I16)->addIncoming(I64, BB23);

	static_cast<PHINode*>(I17)->addIncoming(I14, BB22);
	static_cast<PHINode*>(I17)->addIncoming(I67, BB23);

	static_cast<PHINode*>(I18)->addIncoming(I22, BB26);
	static_cast<PHINode*>(I18)->addIncoming(builder.getInt32(0), BB25);

	module.print(outs(), nullptr);
	outs() << "[VERIFICATION] " << (verifyModule(module, &outs()) ? "FAIL\n\n" : "OK\n\n");
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(&module)).create();
	ee->InstallLazyFunctionCreator([](const std::string &fnName) {
		if (fnName == "memset") {
			return reinterpret_cast<void*>(memset);
		} else if (fnName == "simFlush") {
			return reinterpret_cast<void*>(simFlush);
		} else if (fnName == "simRand") {
			return reinterpret_cast<void*>(simRand);
		} else if (fnName == "simPutPixel") {
			return reinterpret_cast<void*>(simPutPixel);
		}
	});
	ee->finalizeObject();
	ArrayRef<GenericValue> noargs;
	simInit();
	ee->runFunction(appFunc, noargs);
	simExit();
}
