#include <iostream>
#include <cstdlib>
#include "ArrayQueue.h"
#include "LinkedQueue.h"
using std::cout;
using std::endl;
using std::string;
int main(int argc, const char * argv[]) {
cout << "Testing Queue Implementations..." << endl;
// Queue<int> * q1 = new ArrayQueue<int> {};
// Queue<int> * q2 = new LinkedQueue<int> {};
// test!
// delete q1;
// delete q2;


// LinkedQueue Testing
cout << "Testing LinkedQueue . . . " << endl;
Queue<int> * q1 = new LinkedQueue<int> ();
q1->enqueue(5);
q1->enqueue(4);
q1->enqueue(3);
q1->enqueue(2);
q1->enqueue(1);

cout << "Print size: " << q1->size() << endl;
cout << "Dequeue: " << q1->dequeue() << endl;
cout << "Peek: " << q1->peek() << endl;
cout << "Empty: " << q1->empty() << endl;


return EXIT_SUCCESS;
}
