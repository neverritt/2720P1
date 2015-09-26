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
	//top = other.top;
	cout << "Copy called" << endl;
	//delete [] array;
	count = 0;
	maxSize = 10;
	top = -1;
	// copying the array
	//T * temp = new T[maxSize];
	for(int i = 0;i < other.count; i++){
		this->push(other.array[i]);
		cout << "Pushing" << endl;
		//temp[i] = other.array[i];
	}
	cout << "Done Pushing" << endl;
	//delete [] array; //emptying array just in case
	//cout << "Delete worked" << endl;
	//array = temp;
	//cout << "set array to temp" << endl;
	//delete [] temp;
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
		//count = count + 1;
		// new array increases size by 1
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

