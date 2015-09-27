#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#include "Queue.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
* An array-based queue implementation.
*/
template<typename T>
class ArrayQueue : public Queue<T> {
// instance/state variables
public:
int maxSize = 10;
int tail = -1;
int count = 0;
T * array = new T[maxSize];

// Default Constructor
ArrayQueue(void) = default;

// Copy Constructor
ArrayQueue(const ArrayQueue<T> & other) {
	count = 0;
	maxSize = 10;
	tail = -1;
	for(int i = 0; i < other.count; i++){
		this->enqueue(other.array[i]);
	}
} // ArrayQueue

// Destructor
virtual ~ArrayQueue(void) {
	maxSize = 10;
	tail = -1;
	delete [] array;
} // ~ArrayQueue

// adds an item to the rear of this queue
void enqueue(T data){
	count++;
	tail++; // increment tail
	// resizing array if count exceeds maxSize
	if(count>maxSize){
		maxSize = maxSize + (count-maxSize); // +1
		T * temp = new T[maxSize];
		// copy elements
		for(int i = 0; i < count; i++){
			temp[i] = array[i];
		}
		// delete old array, replace with temp
		delete [] array;
		array = temp;
	}
	array[tail] = data; // enqueuing the data
}

// removes the item at the front of this queue and returns it
T dequeue(void){
	T data;
	if(empty()){
		cout << "Attempted to dequeue empty list. Exiting." << endl;
		exit(EXIT_FAILURE);
	}
	else{
		data = array[0]; 
	}
	count--;
	if(count>0){
		// Moving all data to the left
		for(int i = 0; i < count; i++){
			array[i] = array[i+1];
		}
	}
	return data;
}

// returns item at the front of this queue
T peek(void) const {
	T data;
	if(count == 0){
		cout << "Attempted to peek at empty list." << endl;
		exit(EXIT_FAILURE);
	} else {
	data = array[0];
	}
	return data;
}

// returns the number of elements in this queue
const int size(void) const{
	return count;
}

// returns if size is 0
const bool empty() const {
	return size() == 0;
}

}; // ArrayQueue
#endif /* ARRAY_QUEUE_H */

