.PHONY: build run clean

build:
	clang -Iinclude sim/sim.c src/*.c -lSDL2 -o app.out

run: build
	./app.out

clean:
	rm -f app.out