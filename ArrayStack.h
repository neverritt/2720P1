#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "Stack.h"
#include <iostream>
using namespace std;

/**
* An array-based stack implementation.
*/

template<typename T>
class ArrayStack : public Stack<T> {

// instance/state variables
public:
int maxSize = 10;
int count = 0;
int top = -1;
T * array = new T[maxSize];

// Default Constructor
ArrayStack(void) = default;

// Copy Constructor
ArrayStack(const ArrayStack<T> & other) {
	// same initial values, since push changes them
	count = 0;
	maxSize = 10;
	top = -1;
	// copying the array from other, using push
	for(int i = 0;i < other.count; i++){
		this->push(other.array[i]);
	}
} // ArrayStack
  
// Destructor
~ArrayStack(void) {
	delete [] array;
	count = 0;
	top = -1;
	maxSize = 10;
} // ~ArrayStack

// Pushes an item onto the top of this stack
void push(T data){
	top++;
	count++;
	// allocate memory for a new array
	if (count > maxSize){
		maxSize = maxSize + (count-maxSize);
		T * temp = new T[maxSize];
		// copy elements
		for(int i = 0; i < count; i++){
			temp[i] = array[i];
		}
		// delete the old array, replace with temp
		delete [] array;
		array = temp;
	}
	array[top] = data;
}

// Removes the item at the top of this stack and returns that item
T pop(void){
	T popped;
	if (count!=0){
		popped = array[top];
		count--;
		top--;
	}
	return popped;
}

// Returns the item at the top of this stack
T peek(void) const {
	return array[top];	
}

// Returns the number of elements in this stack
const int size(void) const {
	return count;
}

// Returns whether or not this stack is empty
const bool empty() const {
	return size() == 0;
}

// TODO implement other functions
}; // ArrayStack
#endif /* ARRAY_STACK_H */

