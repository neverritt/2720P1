CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -c $(DEBUG)
LFLAGS = $(DEBUG)

compile: sort

sort: sort.o
	$(CC) $(LFLAGS) -o sort sort.o

sort.o: sort.h
	$(CC) $(CFLAGS) -c sort.cpp 

run: sort
	./sort

clean:
	rm -rf *.o
	rm -rf sort
	rm -rf *.dSYM
