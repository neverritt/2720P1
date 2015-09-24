#include <iostream>
#include <cstdlib>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "LinkedList.h"
using std::cout;
using std::endl;
using std::string;
int main(int argc, const char * argv[]) {
cout << "Testing Stack Implementations..." << endl;
// Stack<int> * s1 = new ArrayStack<int> {};
// Stack<int> * s2 = new LinkedStack<int> {};
// test!
// delete s1;
// delete s2;

// testing linked list implementation

LinkedList<int> list;
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
