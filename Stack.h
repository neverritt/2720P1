/** DO NOT MODIFY THIS FILE! */

#ifndef STACK_H
#define STACK_H

/**
 * A Stack represents a last-in-first-out (LIFO) stack of elements. The usual 
 * push and pop operations are provided, as well as a function to peek at the 
 * top item on the stack, and other basic collection functions. When a stack is 
 * first created, it contains no items.
 */
template<typename T>
class Stack {

public:

  /** 
   * Destructor
   */  
  virtual ~Stack(void) { }
  
  /**
   * Pushes an item onto the top of this stack.
   *
   * @param data the item to be pushed onto this stack
   */
  virtual void push(T data) = 0;

  /**
   * Removes the item at the top of this stack and returns that item
   */
  virtual T pop(void) = 0;

  /**
   * Returns the item at the top of this stack without removing it from the
   * stack.
   */
  virtual T peek(void) const = 0;

  /**
   * Returns the number of elements in this stack.
   */
  virtual const int size(void) const = 0;

  /**
   * Returns whether or not this stack is empty.
   */
  const bool empty() const {
    return size() == 0;
  } // empty
  
}; // Stack

#endif /* STACK_H */


