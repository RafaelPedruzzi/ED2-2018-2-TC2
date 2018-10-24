# Project's makefile
#
# Rafael Belmock Pedruzzi
#

CC = gcc

CFLAGS = -Wall -Wextra -lm -g

SRC = src/

BIN = bin/

PROBLEM = 5

PROBLEM2 = 20

PROBLEM3 = 100

PROBLEM4 = 1000

PROBLEM5 = 10000

PROBLEM6 = 100000

PROBLEM7 = 1000000

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

memcheck: $(BIN)trab2
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM).txt && cd ..

run: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM).txt && cd ..

memcheck2: $(BIN)trab2
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM2).txt && cd ..

run2: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM2).txt && cd ..

memcheck3: $(BIN)trab2
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM3).txt && cd ..

run3: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM3).txt && cd ..

memcheck4: $(BIN)trab2
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM4).txt && cd ..

run4: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM4).txt && cd ..

memcheck5: $(BIN)trab2
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM5).txt && cd ..

run5: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM5).txt && cd ..

memcheck6: $(BIN)trab2
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM6).txt && cd ..

run6: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM6).txt && cd ..

memcheck7: $(BIN)trab2
	cd $(BIN) && valgrind ./trab2 $(IN)/$(PROBLEM7).txt && cd ..

run7: $(BIN)trab2
	cd $(BIN) && ./trab2 $(IN)/$(PROBLEM7).txt && cd ..
