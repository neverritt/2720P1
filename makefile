CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bst

bst: bst.o
	$(CC) $(LFLAGS) -o bst bst.o

bst.o: bst.h
	$(CC) $(CFLAGS) -c bst.cpp 

run: bst
	./bst

clean:
	rm -rf *.o
	rm -rf bst
	rm -rf *.dSYM
