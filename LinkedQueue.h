#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include "Queue.h"
/**
* An queue implementation based on a doubly linked list.
*/
template<typename T>
class LinkedQueue : public Queue<T> {
// instance/state variables
public:
// Default Constructor
LinkedQueue(void) = default;
// Copy Constructor
LinkedQueue(const LinkedQueue<T> & other) {
// TODO implement a copy constructor
} // LinkedQueue
// Destructor
virtual ~LinkedQueue(void) {
// TODO implement the destructor
} // ~LinkedQueue
// TODO implement other functions
}; // LinkedQueue
#endif /* LINKED_QUEUE_H */