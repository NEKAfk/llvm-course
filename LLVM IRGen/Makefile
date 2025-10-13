.PHONY: build_implementor build_ir_gen_app

build_implementor:
	clang++ -std=c++23 $$(llvm-config --cppflags --ldflags --libs) implementor.cpp -o implementor.out

build_ir_gen_app: build
	clang++ -std=c++23 $$(llvm-config --cppflags --ldflags --libs) ir_gen_app.cpp ../SDL/sim/sim.c -lSDL2 -I../SDL/include -o ir_gen_app.out