#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
using namespace std;

// forward declation of LinkedList
template<typename T>
class LinkedList;

/**
 * A doubly-linked list constructor
 */


/**
* Represents a node in a doubly-linked list.
*/
template<typename T>
class Node {
	friend class LinkedList<T>;
	T data;
	Node<T> * prev = nullptr;
	Node<T> * next = nullptr;
	//Node(T);
};

//Node::Node(T nodeData) {
//	data = nodeData;
//}

/**
* A doubly-linked list data structure.
*/
template<typename T>
class LinkedList {
public:
	Node<T> * head = nullptr; // pointer to head node
	Node<T> * tail = nullptr;
	int size = 0;
/**
* Adds an item to the end of this list.
*
* @param data the item to append
*/
void append(T data){
	// create new Node with each variable
	// could use malloc
	Node<T> newNode;
	newNode.data = data;
	newNode.prev = tail; //tail
	tail = newNode;
	newNode.next = NULL;
	size++;
}

/**
* Removes all elements from this list.
*/
void clear(void) {
	size = 0;
	// start at head
	Node<T> temp = head;
	while(temp != NULL){
		// data is null
		temp.prev = NULL;
		temp = temp.next;
	}
}

/**
* Returns the item at the given index location.
*
* @param i the index of the item to return
*/
T get(int i) const {
	Node<T> temp = head;
	if (i >= size){
		cout << "Index is outside of range." << endl;
		return;
	}
	else
	for(int j = 0; j<i; j++){
		temp = temp.next;	
	}
	return temp.data;
	// could start at head and count
	// could have int that increases when node is added beforehand
	// for i times, go to next node?
	// return temp data	
}

/**
* Adds an item to the list at the specified index location.
*
* @param i the index where to insert the item
* @param data the item to insert
*/
void insert(int i, T data){
	if (i >= size){
		cout << "Index is outside of range." << endl;
	}
	else{
		Node<T> newNode;
		newNode.data = data;
		newNode.next = head;
		
		// for loop gets newNode to point at the node that will be after it post-insertion
		for(int j = 0; j<i; j++){
			newNode.next = newNode.next.next;
		}
		// gets newNode's prev ptr to point at the node that will be before it post-insertion
		newNode.prev = newNode.next.prev;

		// gets the nodes before and after newNode to point to it instead of each other
		newNode.next.prev = newNode;
		newNode.prev.next = newNode;
		
	}
}

/**
* Adds an item to the end of this list.
*
* @param data the item to prepend
*/
void prepend(T data){
	// when node is null after going next?
	// create new Node with each variable
	// could use malloc
	Node<T> newNode;
	newNode.data = data;
	newNode.next = head; // nodes next is set to head
	newNode.prev = NULL;
	head = newNode;
}

/**
* Sets the value of element at the given index.
*
* @param i the index of the element to set
* @param data the value to set
*/
void set(int i, T data){
	Node<T> temp = head;
	if (i >= size){
		cout << "Index is outside of range." << endl;
	}
	else {
		for(int j = 0; j<i; j++){
			temp = head.next;	
		}
		temp.data = data;
	}
}

/**
* Returns the number of elements in this list.
*/
const int size() const {
	return size;
}

/**
* Returns whether or not this linked list is empty. */
const bool empty() const {
	return size() == 0;
} // empty

}; // LinkedList
#endif /** LINKED_LIST_H */

