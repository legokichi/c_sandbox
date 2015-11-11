INCLUDE = -I./include
CC = gcc -std=c11
CFLAGS = -O3
EMCC = emcc -std=c11
EMFLAGS = -O3 -g3 --js-opts 1 --closure 2
DIST = -o ./bin/a.out

default:
	make build
	make run

build: ./src/*.c
	$(CC) $(CFLAGS) $(INCLUDE) $(DIST) $^

run:
	./bin/a.out test.txt

debug: CFLAGS = -O1 -g
debug: build

asmjs: ./src/*.cpp
	$(EMCC) $(EMFLAGS) $(INCLUDE) $(DIST).js $^

debugjs: EMFLAGS = -O1 -g -s INLINING_LIMIT=10
debugjs: asmjs

runjs:
	cd ./bin
	node a.out.js ../test.txt
