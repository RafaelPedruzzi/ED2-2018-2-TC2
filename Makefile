# Project's makefile
#
# Rafael Belmock Pedruzzi
#

CC = gcc

CFLAGS = -Wall -Wextra -lm -g

SRC = src/

BIN = bin/

PROBLEM = 5

IN = ../in

all: $(BIN)trab2

$(BIN)trab2: main.o worstFit.o bestFit.o heap.o bst.o
	$(CC) -o $@ $^ $(CFLAGS)

main.o: $(SRC)main.c
	$(CC) -c $^ $(CFLAGS)

worstFit.o: $(SRC)worstFit.c
	$(CC) -c $^ $(CFLAGS)

bestFit.o: $(SRC)bestFit.c
	$(CC) -c $^ $(CFLAGS)

heap.o: $(SRC)heap.c
	$(CC) -c $^ $(CFLAGS)

bst.o: $(SRC)bst.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o

debug: $(BIN)trab2
	cd $(BIN) && gdb --args trab2 $(IN)/$(PROBLEM).txt && cd ..

memcheck: $(BIN)trab1
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM).txt && cd ..

run: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM).txt && cd ..
