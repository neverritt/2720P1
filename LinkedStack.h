#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include "Stack.h"
/**
* A stack implementation based on a doubly linked-list.
*/
template<typename T>
class LinkedStack : public Stack<T> {
// instance/state variables
public:
// Default Constructor
LinkedStack(void) = default;
// Copy Constructor
LinkedStack(const LinkedStack<T> & other) {
// TODO implement a copy constructor
} // LinkedStack
  // Destructor
  ~LinkedStack(void) {
// TODO implement the destructor
} // ˜LinkedStack
// TODO implement other functions
}; // LinkedStack
#endif /* LINKED_STACK_H */

