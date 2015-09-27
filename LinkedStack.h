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
LinkedList<T> stack = new LinkedList<T> ();

// Default Constructor
LinkedStack(void) = default;

// Copy Constructor
LinkedStack(const LinkedStack<T> & other) {
	// sets up initial list
	LinkedList<T> stack = new LinkedList<T>();
	
	for( int i = 0; i < other.size(); i++ ) {
		T otherData = other.get( i );
		this->push( otherData );
	}
} // LinkedStack


// Destructor
~LinkedStack(void) {
	stack.clear();
} // ˜LinkedStack

// TODO implement other functions


/**
 * pushes item onto top of stack
 *
 * @param data the item to pushed onto stack
 */
void push( T data ) {
	stack.prepend( data );
}


/**
 * Removes item at top of the stack & returns the item
 */
T pop( void ) {
	if( stack.size() < 1 ) {
		cout << "Stack is empty" << endl;
		exit( EXIT_FAILURE );
	}
	else {
		T data = stack.get( 0 );
		stack.remove( 0 );
		return data;
	}
}


/**
 * Returns Item at top of stack w/out removing from stack
 */
T peek( void ) const {
	return stack.get( 0 );
}


T get( int i ) {
	return stack.get( i );
}


/**
 * Returns num elements in list
 */
const int size( void ) const {
	return stack.size();
}


/**
 * Returns if stack is empty or not
 */
const bool empty() const {
	return size() == 0;
}
}; // LinkedStack
#endif /* LINKED_STACK_H */

