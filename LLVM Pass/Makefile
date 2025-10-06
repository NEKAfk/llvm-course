.PHONY: build_pass build_llvm_ir build_app

build_pass:
	clang++-20 Pass.cpp -fPIC -shared -I$$(llvm-config-20 --includedir) -o libPass.so -std=c++23

build_llvm_ir:
	clang-20 -emit-llvm -S -fpass-plugin=./libPass.so ../SDL/IR/app.ll -o app.ll

build_app:
	clang-20 -I ../SDL/include ./app.ll ../SDL/sim/sim.c ../SDL/src/start.c ./log.c -lSDL2 -o app.out -O3