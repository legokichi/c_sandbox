DIST = ./bin
MAIN = $(DIST)/a.out
SRC = ./src
INCLUDE = -I../duxcalib
default:
	make main
	make run

run:
	./$(MAIN)

main: ../duxcalib/duxcalib.c
	gcc $(INCLUDE) -o $(MAIN) $(SRC)/main.c $^
