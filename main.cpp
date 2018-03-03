#include "Header.h"
#include "Queue.cpp"


int main()
{
	AllInOne obj;
	int i;

	Queue <AllInOne> aioQueue;

	cin >> obj;
	aioQueue.enqueue(obj);
	
	cout <<"Show object: "<< endl;
	aioQueue.printQueue();

	/*aioQueue.dequeue(obj[1]);

	cout <<"\nAfter deleting: "<< endl;
	aioQueue.printQueue();*/

	return 0;
}