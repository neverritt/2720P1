#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include "Queue.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


/**
* A queue implementation based on a doubly linked list.
*/
template<typename T>
class LinkedQueue : public Queue<T> {

public:

// instance/state variables
LinkedList<T> * stack = new LinkedList<T> ();


// Default Constructor
LinkedQueue(void) = default;


// Copy Constructor
LinkedQueue(const LinkedQueue<T> & other) {
	//LinkedList<T> stack = new LinkedList<T> ();

	for( int i = 0; i < other.stack->size(); i++ ) {
		T otherData = other.stack->get( i );
		this->enqueue( otherData );
	}
} // LinkedQueue


// Destructor
~LinkedQueue(void) {
	delete stack;
} // ~LinkedQueue


// TODO implement other functions


/**
 * Adds an item to the rear of the queue.
 *
 * @param data the item to be enqueued
 */
void enqueue( T data ) {
	stack->append( data );
}


/**
 * Removes the item at the front of this queue and returns that item
 */
T dequeue( void ) {
	if( stack->size() < 1 ) {
		cout << "No more items to dequeue" << endl;
		exit ( EXIT_FAILURE);
	}
	else {
		T data = stack->get( 0 );
		stack->remove( 0 );
		return data;
	}
}


/**
 * Returns the item at the front of the queue without removing it
 * from the queue
 */
T peek( void ) const {
	if(stack->size() < 1){
		cout << "Attempted to peek at empty queue. Exiting." << endl;
		exit( EXIT_FAILURE);
	}
	return stack->get( 0 );
}


/**
 * Returns the number of elements in this queue
 */
const int size( void ) const {
	return stack->size();
}


}; // LinkedQueue
#endif /* LINKED_QUEUE_H */
