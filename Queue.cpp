#include "Queue.h"

template< class T >
Queue< T >::Queue():
beginPtr(0), endPtr(0)
{}
//---------------------------------------------------------------
template< class T >
Queue< T >::~Queue()
{
	if (!isEmpty())
	{
		//cout <<"Destructor of the class Queue"<< endl;

		QueueElem< T > *currentPtr = beginPtr;
		QueueElem< T > *tempPtr;

		while (currentPtr)
		{
			tempPtr = currentPtr;
			//cout <<"Destroying "<< tempPtr -> info << endl;
			currentPtr = currentPtr -> nextPtr;
			delete tempPtr;
		}
	}

	cout <<"All elements destroyed"<< endl;
}
//----------------------------------------------------------
template< class T >
void Queue< T >::enqueue(const T& value)
{
	QueueElem< T > *newPtr = getNewElem(value);

	if (isEmpty())
		beginPtr = endPtr = newPtr;
	else
	{
		endPtr -> nextPtr = newPtr;
		endPtr = newPtr;
	}
}
//----------------------------------------------------------
template< class T >
bool Queue< T >::dequeue(const T& value)
{
	if (isEmpty())
		return false;
	else
	{
		QueueElem< T > *tempPtr = beginPtr;

		if (beginPtr == endPtr)
			beginPtr = endPtr = 0;
		else
			beginPtr = beginPtr -> nextPtr;

		//value = tempPtr -> info;
		delete tempPtr;
		return true;
	}
}
//----------------------------------------------------------
template< class T >
bool Queue< T >::isEmpty()
{
	return beginPtr == 0;
}
//----------------------------------------------------------
template< class T >
QueueElem< T >* Queue< T >::getNewElem(const T& value)
{
	return new QueueElem< T >(value);
}
//----------------------------------------------------------
template< class T >
void Queue< T >::printQueue()
{
	if (isEmpty())
	{
		cout <<"\nThe Queue is empty!"<< endl;
		return;
	}

	QueueElem< T > *currentPtr = beginPtr;

	for (int i = 1; currentPtr; ++i)
	{
		cout << i <<"."<< currentPtr -> info <<"  ";
		currentPtr = currentPtr -> nextPtr;
	}
}