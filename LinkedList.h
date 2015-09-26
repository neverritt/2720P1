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
		tail = head;
	}
	// if not first node, update tail
	else {
		tail->next = newNode;
		tail = tail->next;			
	}
	length++;
	
	//insert( size(), data);
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

	delete temp;	// deletes final node

	// set head and tail to null
	head = nullptr;
	tail = nullptr;

	length = 0;	// resets length
}

/**
* Returns the item at the given index location.
*
* @param i the index of the item to return
*/
T get(int i) const {
	Node<T> * temp;
	temp = head;
	if (i >= length || i < 0){
		cout << "Index is outside of range." << endl;
		exit (EXIT_FAILURE);
	}
	else{

		for( int j = 0; j < i; j++ ){
		// moves through the list one by one to reach desired index
			temp = temp->next;	
		}
		return temp->data;
	}
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
		//Node<T> * newNode = Node<T>();
		//Node<T> * sucessorPtr;
		//Node<T> * predecessorPtr;
		//newNode->data = data;
		//sucessorPtr = head;
		Node<T> * traverse = head;
		
		// for loop gets a ptr to the successor of newNode post-insertion
		for( int j = 1; j < i; j++ ) {
			traverse = traverse->next;
			//if( j == i-1 ) {
			//	predecessorPtr = sucessorPtr;
			//}
			//sucessorPtr = sucessorPtr->next;
		}
		Node<T> * temp = traverse->next;
		traverse->next = new Node<T>;
		(traverse->next)->next = temp;
		(traverse->next)->data = data;
		//newNode.next = sucessorPtr;		// sets newNode.next to it's successor
		//newNode.prev = predecessorPtr;		// successor of newNode's prev is still set to what will be
		
		// gets the nodes before and after newNode to point to it instead of each other
		//predecessorPtr->next = &newNode;
		//sucessorPtr->prev = &newNode;
		length++;

		//if( i == 0 )
		//	head = &newNode;
		//else if ( i == length - 1 )
		//	tail = &newNode;
	}
}

/**
* Adds an item to the end of this list.
*
* @param data the item to prepend
*/
void prepend(T data){
	Node<T> * newNode = new Node<T>();
	newNode->data = data;
	newNode->next = head; // nodes next is set to head
	head = newNode;
	length++;

	// If first Node, tail = head
	if(tail == nullptr)
		tail = head;
	//insert( 0, data );
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

