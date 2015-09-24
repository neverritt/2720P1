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
	//ArrayStack() copy = new ArrayStack();
	// declare new dynamic array
	//T * newArray = new T[count];
	// copy data from array to newArray
	//for (int i = 0; i < count; i++){
	//	newArray[i] = array[i];
	//}
} // ArrayStack
  
// Destructor
~ArrayStack(void) {
	delete [] array;
} // ~ArrayStack

// Pushes an item onto the top of this stack
void push(T data){
	top++;
	count++;
	// allocate memory for a new array
	if (count > maxSize){
		//count = count + 1;
		// new array increases size by 1
		T * temp = new T[maxSize+(count-maxSize)];
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
		//array[top] = nullptr;
		count--;
		top--;
		//return popped;
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

