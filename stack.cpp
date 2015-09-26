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
Stack<int> * s2 = new LinkedStack<int> {};
s2->push(5);
s2->push(4);
s2->push(3);
s2->push(2);
s2->push(1);
cout << "Peek: " << s2->peek() << endl;
cout << "Popping: " << s2->pop() << endl;
cout << "Peek: " << s2->peek() << endl;
cout << "Size: " << s2->size() << endl;
cout << "Is empty? " << s2->empty() << endl;
cout << "Test copy constructor: " << endl;
Stack<int> * s3 = s2;
cout << "Top of new stack: " << s3->peek() << endl;
delete s2;
delete s3;

cout << endl << endl;


// testing linked list implementation

LinkedList<int> list = new LinkedList<int> ();
cout << "initial size is: " << list.size() << endl;

list.prepend( 1 );
cout << "Prepend 1 to list: " << endl << "size: " << list.size() << "  get first index: " << list.get(0) << endl;

list.append( 3 );
list.append( 4 );
list.insert( 1, 2 );
list.prepend( 0 );

cout << "size: " << list.size() << " should be 5." << endl;
/*for( int k = 0; k < list.size(); k++ ){
	cout << list.get( k ) << " ";
}*/

cout << list.get(0) << " " << list.get(1) << " " << list.get(2) << " " << list.get(3) << " " << list.get(4);
cout << endl;

cout << "list empty? " << list.empty() << endl;

list.set( 2, 14 );
cout << "changed index to 14: " << list.get( 2 ) << endl;
list.clear();
cout << "Is list empty after clear? " << list.empty() << endl;

return EXIT_SUCCESS;
} // main
