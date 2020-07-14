#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"

template <typename T>
class Queue{
private:
	static const int QUEUESIZE;
	int front_;
	int rear_;
	Array<T> arr_;
public:
	explicit Queue(int size = Queue<T>::QUEUESIZE);
	
	bool operator==(const Queue<T>& rhs) const;
	
	int size() const;
	void push(const T& data); 
	const T pop();	
};

#include <cassert>
template <typename T>
const int Queue<T>::QUEUESIZE = 100;

template <typename T>
Queue<T>::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}

template <typename T>
bool Queue<T>::operator==(const Queue<T>& rhs) const
{
	if (rear_ != rhs.rear_ || front_ != rhs.front_)
		return 0;
	return arr_ == rhs.arr_;
}

template <typename T>
int Queue<T>::size() const
{
	return arr_.size();
}

template <typename T>
void Queue<T>::push(const T& data)
{
	assert(rear_ != arr_.size());    
	arr_[rear_] = data;
	++rear_;		
}

template <typename T>
const T Queue<T>::pop()
{
	assert(front_ != rear_);  

	return arr_[front_++];
}

#endif
