#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#include "Queue.h"
/**
* An array-based queue implementation.
*/
template<typename T>
class ArrayQueue : public Queue<T> {
// instance/state variables
public:
// Default Constructor
ArrayQueue(void) = default;
// Copy Constructor
ArrayQueue(const ArrayQueue<T> & other) {
// TODO implement a copy constructor
} // ArrayQueue
// Destructor
virtual ~ArrayQueue(void) {
// TODO implement the destructor
} // ~ArrayQueue
// TODO implement other functions
}; // ArrayQueue
#endif /* ARRAY_QUEUE_H */

