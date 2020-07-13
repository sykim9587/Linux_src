#include <cassert>
#include "queue.h"

const int Queue::QUEUESIZE = 100;

Queue::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}

bool Queue::operator==(const Queue& rhs) const
{
	if (rear_ != rhs.rear_ || front_ != rhs.front_)
		return 0;
	return arr_ == rhs.arr_;
}

int Queue::size() const
{
	return arr_.size();
}

void Queue::push(int data)
{
	assert(rear_ != arr_.size());    
	arr_[rear_] = data;
	++rear_;		
}

int Queue::pop()
{
	assert(front_ != rear_);  

	return arr_[front_++];
}

