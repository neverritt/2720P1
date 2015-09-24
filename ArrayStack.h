#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "Stack.h"

/**
* An array-based stack implementation.
*/

template<typename T>
class ArrayStack : public Stack<T> {

// instance/state variables
public:
int count = 1;
T * array = new T[1];
int top = -1;

// Default Constructor
ArrayStack(void) = default;

// Copy Constructor
ArrayStack(const ArrayStack<T> & other) {
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
	top = top + 1;
	if ((top+1) == count){
		count = count + 1;
		T * temp = new T[count];
		for(int i = 0; i < count; i++){
			temp[i] = array[i];
		}
		delete [] array;
		array = temp;
	}
	array[top] = data;
}

// Returns the item at the top of this stack
T peek(void) const {
	return array[top];	
}

// Returns the number of elements in this stack
const int size(void) const {
	return count-1;
}

// Returns whether or not this stack is empty
const bool empty() const {
	return size() == 0;
}

// TODO implement other functions
}; // ArrayStack
#endif /* ARRAY_STACK_H */

