.PHONY: antlr build build_test run run_test

antlr:
	antlr4 -Dlanguage=Cpp Grammar.g4 -visitor -o generated

build: 
	clang++ main.cpp ./generated/*.cpp ../SDL/sim/sim.c -I../SDL/include/ -I.generated/ -I/home/nikita/Documents/vcpkg/installed/x64-linux/include/antlr4-runtime/ -L/home/nikita/Documents/vcpkg/installed/x64-linux/debug/lib -lantlr4-runtime -lSDL2 $$(llvm-config --cppflags --ldflags --libs)
run: build
	./a.out app.pdd

build_test: 
	clang++ ./tests/test.cpp ./generated/*.cpp -I.generated/ -I/home/nikita/Documents/vcpkg/installed/x64-linux/include/antlr4-runtime/ -L/home/nikita/Documents/vcpkg/installed/x64-linux/debug/lib -lantlr4-runtime $$(llvm-config --cppflags --ldflags --libs)

run_test: build_test
	./a.out ./tests/expr.pdd $(fName)