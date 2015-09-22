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
// Default Constructor
ArrayStack(void) = default;
// Copy Constructor
ArrayStack(const ArrayStack<T> & other) {
// TODO implement a copy constructor
} // ArrayStack
  // Destructor
  ~ArrayStack(void) {// TODO implement the destructor
} // ~ArrayStack
// TODO implement other functions
}; // ArrayStack
#endif /* ARRAY_STACK_H */

