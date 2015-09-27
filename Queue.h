/** DO NOT MODIFY THIS FILE! */
#ifndef QUEUE_H
#define QUEUE_H
/**
* A Queue represents a first-in-first-out (FIFO) queue of elements. The usual
* enqueue and dequeue operations are provided, as well as a function to peek
* at the front item in the queue, and other basic collection functions. When a
* queue is first created, it contains no items.
*/
template<typename T>
class Queue {
public:
/**
* Destructor
*/
virtual ~Queue(void) { }
/**
* Adds an item to the rear of this queue.
*
* @param data the item to be enqueued
*/
virtual void enqueue(T data) = 0;
/**
* Removes the item at the front of this queue and returns that item
*/
virtual T dequeue(void) = 0;
/**
* Returns the item at the front of this queue without removing it from the
* queue.
*/
virtual T peek(void) const = 0;
/**
* Returns the number of elements in this queue.
*/
virtual const int size(void) const = 0;
/**
* Returns whether or not this queue is empty.
*/
const bool empty() const {
return size() == 0;
} // empty
}; // Queue
#endif /* QUEUE_H */

