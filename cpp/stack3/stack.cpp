#include <cassert>
#include "stack.h"

const int Stack::STACKSIZE = 100;

Stack::Stack(int size)
: arr_(size), tos_(0)
{

}
/*
Stack::Stack(const Stack& rhs)
: arr_(rhs.arr), tos(rhs.tos_)
{

}

Stack::~Stack()
{

}

Stack& Stack::operator=(const Stack& rhs)
{
	arr_ = rhs.arr_;
	tos_ = rhs.tos_;
}
*/
bool Stack::operator==(const Stack& rhs) const
{
	if (tos_ != rhs.tos_) return false;
	
	return arr_ == rhs.arr_;
}

int Stack::size() const
{
	return arr_.size();
}

void Stack::push(int data)
{
	assert(tos_ != size());
	arr_[tos_] = data;
	++tos_;
}

int Stack::pop()
{
	assert(tos_);
	--tos_;
	return arr_[tos_];
}

