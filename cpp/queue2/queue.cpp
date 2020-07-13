#include <cassert>
#include "queue.h"

const int Queue::QUEUESIZE = 100;

Queue::Queue(int size)
:pArr_(new int[size]), size_(size), front_(0), rear_(0)
{
	assert(pArr_ );
}

Queue::Queue(const Queue& rhs)
:pArr_(new int[rhs.size_]), size_(rhs.size_), front_(rhs.front_), rear_(rhs.rear_)
{
	assert(pArr_);
	for (int i = rhs.front_; i < rhs.rear_; ++i)
		pArr_[i] = rhs.pArr_[i];
}

Queue::~Queue()
{
	delete [] pArr_;
}

Queue& Queue::operator=(const Queue& rhs)
{
	if (this != &rhs) {
		delete [] pArr_;
		pArr_ = new int[rhs.size_];
		size_ = rhs.size_;
		front_ = rhs.front_;
		rear_ = rhs.rear_;
		
		for (int i = rhs.front_; i < rhs.rear_; ++i)
			pArr_[i] = rhs.pArr_[i];
	}
	return *this;
}

bool Queue::operator==(const Queue& rhs) const
{
	if (size_ != rhs.size_ || rear_ != rhs.rear_ || front_ != rhs.front_);
		return 0;
	int i;
	for (i = rhs.front_; i < rhs.rear_; ++i)
		if(pArr_[i] != rhs.pArr_[i])
			break;
	
	return (i == rhs.rear_);
}

int Queue::size() const
{
	return size_;
}

void Queue::push(int data)
{
	assert(rear_ != size_);    
	pArr_[rear_] = data;
	++rear_;		
}

int Queue::pop()
{
	assert(front_ != rear_);  

	return pArr_[front_++];
}

