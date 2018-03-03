#include <iostream>

#include "QueueList.h"

using namespace std;

template< class T >
class Queue
{
public:
	Queue();
	~Queue();

	void enqueue(const T&);
	bool dequeue(const T&);
	bool isEmpty();
	void printQueue();

private:
	QueueElem< T > *beginPtr, *endPtr;

	QueueElem< T > *getNewElem(const T&);
};