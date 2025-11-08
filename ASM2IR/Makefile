.PHONY: build run clean

MOD ?= 1

build:
	clang++ $$(llvm-config --cppflags --ldflags --libs) src/*.cpp ../SDL/sim/sim.c -Iinclude -lSDL2 -o asm2ir.out

run: build
	./asm2ir.out app.s $(MOD)

clean:
	rm -f asm2ir.out