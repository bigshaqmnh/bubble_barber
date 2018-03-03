template< class T > class Queue;

template< class T >
class QueueElem
{
	friend class Queue <T>;

public:
	QueueElem(const T&);
	T getInfo() const;

private:
	T info;
	QueueElem< T > *nextPtr;
};

template< class T >
QueueElem< T >::QueueElem(const T& inf):
info(inf), nextPtr(0)
{}
//-----------------------------------------------------------
template< class T >
T QueueElem< T >::getInfo() const
{
	return info;
}
