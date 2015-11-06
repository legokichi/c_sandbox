INCLUDE = -I./include
EMCC = ~/emsdk_portable/emscripten/master/emcc

default:
	make main
	make run

run:
	./bin/a.out test.txt

main: ./src/*.c
	gcc -lm $(INCLUDE) -o ./bin/a.out $^

asmjs: ./src/*.c
	$(EMCC) -O3 -g3 --js-opts 1 --closure 2 -v -I./include -o ./bin/a.out.js ./src/*.c

runjs:
	cd ./bin
	node a.out.js test.txt
