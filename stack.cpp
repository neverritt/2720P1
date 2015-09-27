#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "LinkedList.h"
using std::cout;
using std::endl;
using std::string;

int main(int argc, const char * argv[]) {

/**
// ArrayStack Testing
cout << "Testing Array Stack Implementations..." << endl;
ArrayStack<int> * s1 = new ArrayStack<int> {};
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
cout << "Popped should be 12 " << s1->pop() << endl;

cout << "Popped should be 11" << s1->pop() << endl;

cout << "Peeking should be 10" << s1->peek() << endl;

cout << "size is 10" << s1->size() << endl;

ArrayStack<int> s2 = *s1;

cout << "Popped should be 10" << s2.pop() << endl;
cout << "First size still 10" << s1->size() << endl;
cout << "s2 size now 9" << s2.size() << endl;
cout << "Popped should be 10" << s1->pop() << endl;
cout << "Popped should be 9" << s2.pop() << endl;

delete s1;

cout << endl << endl;
**/

/**
// LinkedStack Testing
cout << "Testing LinkedStack . . . " << endl;
LinkedStack<int> * ls = new LinkedStack<int>();
ls->push(5);
ls->push(4);
ls->push(3);
ls->push(2);
ls->push(1);
cout << "Peek: 1" << ls->peek() << endl;
cout << "Popping: 1" << ls->pop() << endl;
cout << "Peek: 2" << ls->peek() << endl;
cout << "Size: 4" << ls->size() << endl;
cout << "Is empty? 0" << ls->empty() << endl;
cout << "Test copy constructor: " << endl;
LinkedStack<int> ls2 = *ls;
cout << "Top of new stack: 2" << ls2.peek() << endl;
delete ls;
cout << "Pop is 2" << ls2.pop() << endl;

cout << endl << endl;
**/


/**
// testing linked list implementation

LinkedList<int> * list = new LinkedList<int>();
cout << "initial size is: " << list->size() << endl;

list->prepend( 1 );
cout << "Prepend 1 to list: " << endl << "size: " << list->size() << "  get first index: " << list->get(0) << endl;

list->append( 3 );
list->append( 4 );
list->insert( 1, 2 );
list->prepend( 0 );

cout << "size: " << list->size() << " should be 5." << endl;

cout << list->get(0) << " " << list->get(1) << " " << list->get(2) << " " << list->get(3) << " " << list->get(4);
cout << endl;

cout << "list empty? " << list->empty() << endl;

list->set( 2, 14 );
cout << "changed index to 14: " << list->get( 2 ) << endl;
list->clear();
cout << "Is list empty after clear? " << list->empty() << endl;
**/


cout << "Time testing Stacks . . . " << endl;

clock_t begin, end;
float time_spent;
LinkedStack<int> * stack = new LinkedStack<int> ();

for( int i = 0; i < 10; i++ ) {
	begin = clock();

	for( int j = 0; j < 1000000; j++ ) {
		stack->push( 0 );
	}

	end = clock();

	time_spent = (float) (end - begin) / CLOCKS_PER_SEC * 1000;
	cout << setprecision(3) << fixed << "Push took: " << time_spent << " seconds" << endl;

	begin = clock();

	for( int j = 0; j < 1000000; j++ ) {
		stack->pop();
	}

	end = clock();

	time_spent = (float) (end - begin) / CLOCKS_PER_SEC * 1000;
	cout << setprecision(3) << fixed << "Pop took: " << time_spent << " seconds" << endl;

	cout << endl;
}


return EXIT_SUCCESS;
} // main
