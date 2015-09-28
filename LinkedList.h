#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>		// cout, endl, etc
#include <stdlib.h>		// exit, EXIT_FAILURE
using namespace std;

// forward declation of LinkedList
template<typename T>
class LinkedList;

/**
* Represents a node in a doubly-linked list.
*/
template<typename T>
class Node {
	friend class LinkedList<T>;
	T data;
	Node<T> * prev = nullptr;
	Node<T> * next = nullptr;
}; // Node

/**
* A doubly-linked list data structure.
*/
template<typename T>
class LinkedList {
public:
	Node<T> * head = nullptr; // pointer to 1st node
	Node<T> * tail = nullptr; // pointer to last node
	int length = 0;


/**
* Adds an item to the end of this list.
*
* @param data the item to append
*/
void append(T data){
	// create new Node
	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	// if first node, tail = head
	if (tail == nullptr){
		head = newNode;
		tail = newNode;
	}
	// if not first node, update tail
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}


/**
* Adds an item to the beginning of this list.
*
* @param data the item to prepend
*/
void prepend(T data){
	Node<T> * newNode = new Node<T>();
	newNode->data = data;
	newNode->next = head; // nodes next is set to head
	head->prev = &newNode;
	head = &newNode;
	length++;

	// If first Node, tail = head
	if(tail == nullptr)
		tail = &newNode;
}


/**
* Adds an item to the list at the specified index location.
*
* @param i the index where to insert the item
* @param data the item to insert
*/
void insert(int i, T data){
	if ( i > length || i < 0 ){
		cout << "Index is outside of range." << endl;
		exit ( EXIT_FAILURE );
	}

	if (i == 0){
		prepend(data);
	}
	else if(i==length){
		append(data);
	}
	else{
		Node<T> * traverse = head;
		
		// for loop gets a ptr to the successor of newNode post-insertion
		for( int j = 1; j < i; j++ ) {
			traverse = traverse->next;
		}
		Node<T> * temp = traverse->next;
		traverse->next = new Node<T>;	   // makes node to insert, sets prev to point to it
		(traverse->next)->next = temp;	   // sets next for new node
		(traverse->next)->prev = traverse; // sets prev for new node
		temp->prev = traverse->next;	   // sets next to point to new node
		(traverse->next)->data = data;	   // sets data for new Node
		
		length++;
	}
}


/**
* Returns the item at the given index location.
*
* @param i the index of the item to return
*/
T get(int i) const {
	if (i >= length || i < 0){
		cout << "Index is outside of range." << endl;
		exit (EXIT_FAILURE);
	}
	else{
		Node<T> * nodePtr;
		
		if( length - 1 - i < length / 2 ) {
			nodePtr = tail;
			for( int j = length-1; j > i; j-- ){
				// moves through the list one by one to reach desired index
				nodePtr = nodePtr->prev;	
			}
		}
		else {
			nodePtr = head;
			for( int j = 0; j < i; j++ ){
			// moves through the list one by one to reach desired index
				nodePtr = nodePtr->next;	
			}
		}
		return nodePtr->data;
	}
}


/**
* Sets the value of element at the given index.
*
* @param i the index of the element to set
* @param data the value to set
*/
void set(int i, T data){
	if ( i >= length || i < 0 ){
		cout << "Index is outside of range." << endl;
		exit( EXIT_FAILURE );
	}
	else {
		Node<T> * temp;
		temp = head;
		for(int j = 0; j < i; j++){
			temp = temp->next;	
		}
		temp->data = data;
	}
}


/**
 * removes the node at index from list
 *
 * @param int i index to remove from list
 */
void remove( int i ) {
	if( i < 0 || i >= length ) {
		cout << "Index out of range" << endl;
		exit ( EXIT_FAILURE );
	}
	else {
		// node will point at target to remove
		Node<T> * traverse;
		
		// will set prev and next nodes to point at each other
		if( length == 1 ){
			traverse = head;
		}
		else if( i == 0 ){
			traverse = head;
			head = traverse->next;
			head->prev = nullptr;
		}

		else if ( i == length - 1 ) {
			traverse = tail;
			tail = tail->prev;
			tail->next = nullptr;
		}

		else {
			traverse = head;
			for (int j = 0; j < i; j++){
				traverse = traverse->next;
			}
			(traverse->prev)->next = traverse->next;
			(traverse->next)->prev = traverse->prev;
		}
		// removes target node
		delete traverse;
		length--;
	}
}


/**
* Removes all elements from this list.
*/
void clear(void) {
	// start at head
	Node<T> * temp = head;

	for( int j = 0; j < length; j++ ){ // for loop deletes prev node of all nodes in array
		delete temp->prev;
		temp = temp->next;
	}
	
	if(length!=0){
		delete temp;	// deletes final node
	}
	// set head and tail to null
	head = nullptr;
	tail = nullptr;

	length = 0;	// resets length
}


/**
* Returns the number of elements in this list.
*/
const int size() const {
	return length;
}


/**
* Returns whether or not this linked list is empty. */
const bool empty() const {
	return size() == 0;
} // empty

}; // LinkedList
#endif /** LINKED_LIST_H */

