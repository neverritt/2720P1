CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -c $(DEBUG)
LFLAGS = $(DEBUG)

compile: sort dataGenerator

sort: sort.o
	$(CC) $(LFLAGS) -o sort sort.o

sort.o: sort.h
	$(CC) $(CFLAGS) -c sort.cpp 

run: sort
	./sort

dataGenerator: dataGenerator.o
	$(CC) $(LFLAGS) -o dataGenerator dataGenerator.o

dataGenerator.o:
	$(CC) $(CFLAGS) -c dataGenerator.cpp

clean:
	rm -rf *.o
	rm -rf sort
	rm -rf *.dSYM
	rm -rf dataGenerator
