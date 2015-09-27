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
LinkedQueue<int> * q1 = new LinkedQueue<int> ();
q1->enqueue(5);
q1->enqueue(4);
q1->enqueue(3);
q1->enqueue(2);
q1->enqueue(1);

cout << "Print size: 5 " << q1->size() << endl;
cout << "Dequeue: 5 " << q1->dequeue() << endl;
cout << "Peek: 4 " << q1->peek() << endl;
cout << "Empty: 0 " << q1->empty() << endl;
cout << "size is 4 " << q1->size() << endl;
q1->enqueue(0);
cout << "size is 5 " << q1->size() << endl;

LinkedQueue<int> q2 = *q1;

cout << "Dequeue: 4 " << q2.dequeue() << endl;
cout << "Peek: 3 " << q2.peek() << endl;
cout << "Peek still 4" << q1->peek() << endl;

delete q1;

cout << "Testing LinkedArray . . . " << endl;
ArrayQueue<int> * aq = new ArrayQueue<int> {};
aq->enqueue(11);
aq->enqueue(10);
aq->enqueue(9);
aq->enqueue(8);
aq->enqueue(7);
aq->enqueue(6);
aq->enqueue(5);
aq->enqueue(4);
aq->enqueue(3);
aq->enqueue(2);
aq->enqueue(1);

cout << "Print size: 11 " << aq->size() << endl;
cout << "Dequeue: 11 " << aq->dequeue() << endl;
cout << "Peek: 10 " << aq->peek() << endl;
cout << "Empty: 0 " << aq->empty() << endl;
cout << "size is 10 " << aq->size() << endl;
aq->enqueue(0);
cout << "size is 11 " << aq->size() << endl;

ArrayQueue<int> a2 = *aq;

cout << "Dequeue: 10 " << a2.dequeue() << endl;
cout << "Peek: 9 " << a2.peek() << endl;
cout << "Peek still 10" << aq->peek() << endl;

delete aq;


return EXIT_SUCCESS;
}
