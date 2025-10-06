.PHONY: build_pass build_llvm_ir build_app

build_pass:
	clang++ Pass.cpp -fPIC -shared -I$$(llvm-config --includedir) -o libPass.so -std=c++23

build_llvm_ir:
	clang -emit-llvm -S -fpass-plugin=./libPass.so ../SDL/IR/app.ll -o app.ll

build_app:
	clang -I ../SDL/include ./app.ll ../SDL/sim/sim.c ../SDL/src/start.c ./log.c -lSDL2 -o app.out -O3

analyze_patterns:
	python3 pattern_frequency.py > res.txt