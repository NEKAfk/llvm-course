.PHONY: build run clean ir

build:
	clang-20 -Iinclude sim/sim.c src/*.c -lSDL2 -o app.out

run: build
	./app.out

ir:
	clang-20 -emit-llvm -S src/app.c -I ./include -o IR/app.ll -O1

clean:
	rm -f app.out