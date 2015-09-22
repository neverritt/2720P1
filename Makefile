
CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: stack queue

stack: stack.o
	$(CC) $(LFLAGS) -o stack stack.o

stack.o: Stack.h ArrayStack.h LinkedStack.h LinkedList.h
	$(CC) $(CFLAGS) -c stack.cpp

queue: queue.o
	$(CC) $(LFLAGS) -o queue queue.o

queue.o: Queue.h ArrayQueue.h LinkedQueue.h LinkedList.h
	$(CC) $(CFLAGS) -c queue.cpp

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf *.dSYM
	rm -rf stack
	rm -rf queue