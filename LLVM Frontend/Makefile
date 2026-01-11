.PHONY: antlr build build_test run run_test

antlr:
	antlr4 -Dlanguage=Cpp Grammar.g4 -visitor -o generated

build: 
	clang++-21 main.cpp ./generated/*.cpp ../SDL/sim/sim.c -I/home/nikita/Documents/vcpkg/installed/x64-linux/include/antlr4-runtime/ -I../SDL/include/ -I.generated/ -L/home/nikita/Documents/vcpkg/installed/x64-linux/debug/lib -lantlr4-runtime -lSDL2 $$(llvm-config-21 --cppflags --ldflags --libs)
run: build
	./a.out app.pdd

build_test: 
	clang++-21 ./tests/test.cpp ./generated/*.cpp -I/home/nikita/Documents/vcpkg/installed/x64-linux/include/antlr4-runtime/ -I.generated/ -L/home/nikita/Documents/vcpkg/installed/x64-linux/debug/lib -lantlr4-runtime $$(llvm-config-21 --cppflags --ldflags --libs)

run_test: build_test
	./a.out ./tests/expr.pdd $(fName)