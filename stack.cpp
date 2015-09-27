#include <iostream>
#include <cstdlib>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "LinkedList.h"
using std::cout;
using std::endl;
using std::string;
int main(int argc, const char * argv[]) {


// ArrayStack Testing
cout << "Testing Array Stack Implementations..." << endl;
Stack<int> * s1 = new ArrayStack<int> {};
// test!
s1->push(1);
s1->push(2);
s1->push(3);
s1->push(4);
s1->push(5);
s1->push(6);
s1->push(7);
s1->push(8);
s1->push(9);
s1->push(10);
s1->push(11);
s1->push(12);
cout << "Popped " << s1->pop() << endl;

cout << "Peeking " << s1->peek() << endl;

cout << "size is " << s1->size() << endl;
delete s1;

cout << endl << endl;


// LinkedStack Testing
cout << "Testing LinkedStack . . . " << endl;
Stack<int> * ls = &(new LinkedStack<int>());
ls->push(5);
ls->push(4);
ls->push(3);
ls->push(2);
ls->push(1);
cout << "Peek: " << ls->peek() << endl;
cout << "Popping: " << ls->pop() << endl;
cout << "Peek: " << ls->peek() << endl;
cout << "Size: " << ls->size() << endl;
cout << "Is empty? " << ls->empty() << endl;
cout << "Test copy constructor: " << endl;
//Stack<int> * ls2 = new LinkedStack<int>();
//ls2 = ls;
//cout << "Top of new stack: " << ls2->peek() << endl;
delete ls;
//cout << ls2->pop() << endl;

cout << endl << endl;


// testing linked list implementation

LinkedList<int> * list = new LinkedList<int> ();
cout << "initial size is: " << list->size() << endl;

list->prepend( 1 );
cout << "Prepend 1 to list: " << endl << "size: " << list->size() << "  get first index: " << list->get(0) << endl;

list->append( 3 );
list->append( 4 );
list->insert( 1, 2 );
list->prepend( 0 );

cout << "size: " << list->size() << " should be 5." << endl;
/*for( int k = 0; k < list->size(); k++ ){
	cout << list->get( k ) << " ";
}*/

cout << list->get(0) << " " << list->get(1) << " " << list->get(2) << " " << list->get(3) << " " << list->get(4);
cout << endl;

cout << "list empty? " << list->empty() << endl;

list->set( 2, 14 );
cout << "changed index to 14: " << list->get( 2 ) << endl;
list->clear();
cout << "Is list empty after clear? " << list->empty() << endl;

return EXIT_SUCCESS;
} // main
