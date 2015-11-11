CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -c $(DEBUG)
LFLAGS = $(DEBUG)

compile: sort

bst: sort.o
	$(CC) $(LFLAGS) -o sort sort.o

bst.o: bst.h
	$(CC) $(CFLAGS) -c sort.cpp 

run: bst
	./sort

clean:
	rm -rf *.o
	rm -rf sort
	rm -rf *.dSYM
