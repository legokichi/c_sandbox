INCLUDE = -I./include

default:
	make main
	make run

run:
	./bin/a.out test.txt

main: ./src/*.c
	gcc -v $(INCLUDE) -o ./bin/a.out $^
