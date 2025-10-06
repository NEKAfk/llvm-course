.PHONY: build run clean ir

build:
	clang -Iinclude sim/sim.c src/*.c -lSDL2 -o app.out

run: build
	./app.out

ir:
	clang -emit-llvm -S src/app.c -I ./include -o IR/app.ll -O1

clean:
	rm -f app.out