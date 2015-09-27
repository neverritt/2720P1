#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include "Stack.h"
#include "LinkedList.h"
#include <stdlib.h>	// exit, EXIT_FAILURE
#include <iostream>	// cout, endl
using namespace std;

/**
* A stack implementation based on a doubly linked-list.
*/
template<typename T>
class LinkedStack : public Stack<T> {

public:
//instance/state variables
LinkedList<T> * stack = new LinkedList<T> ();
int top = -1;

// Default Constructor
LinkedStack(void) = default;

// Copy Constructor
LinkedStack(const LinkedStack<T> & other) {
	// sets up initial list
	top = -1;
	//LinkedList<T> stack = new LinkedList<T>();
	
	for( int i = 0; i < other->size(); i++ ) {
		T otherData = other->get( i );
		this->push( otherData );
	}
} // LinkedStack


// Destructor
~LinkedStack(void) {
	top = -1;
	delete stack;
	//stack->clear();
} // ˜LinkedStack

// TODO implement other functions


/**
 * pushes item onto top of stack
 *
 * @param data the item to pushed onto stack
 */
void push( T data ) {
	top++;
	stack->append( data );
}


/**
 * Removes item at top of the stack & returns the item
 */
T pop( void ) {
	T data;
	if( stack->size() < 1 ) {
		cout << "Stack is empty" << endl;
		exit( EXIT_FAILURE );
	}
	else {
		data = stack->get( top );
		stack->remove( top );
	}
	top--;
	return data;
}


/**
 * Returns Item at top of stack w/out removing from stack
 */
T peek( void ) const {
	if( stack->size() < 1) {
		cout << "Attempted to peek at empty Array Stack." << endl;
		exit( EXIT_FAILURE);
	}
	return stack->get( top );
}


T get( int i ) {
	return stack->get( i );
}


/**
 * Returns num elements in list
 */
const int size( void ) const {
	return stack->size();
}


/**
 * Returns if stack is empty or not
 */
const bool empty() const {
	return size() == 0;
}
}; // LinkedStack
#endif /* LINKED_STACK_H */

