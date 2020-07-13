#include <cassert>
#include "stack.h"

const int Stack::STACKSIZE = 100;

void Stack::set_arr(const int* pArr, int size, int tos) {
	pArr_ = new int[size];
	assert(pArr_);
	size_ = size;
	tos_ = tos;
	
	for (int i = 0; i <= tos; ++i)
		pArr_[i] = pArr[i];
}

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0)
{

}

Stack::Stack(const int* pArr, int size, int tos)
{
	set_arr(pArr, size, tos);
}

Stack::Stack(const Stack& rhs)
{
	set_arr(rhs.pArr_, rhs.size_, rhs.tos_);
}

Stack::~Stack() {
	delete [] pArr_;
}

Stack& Stack::operator=(const Stack& rhs) {
	if (this == &rhs) return *this;

	delete [] pArr_;
	set_arr(rhs.pArr_, rhs.size_, rhs.tos_);
	
	return *this;
}

bool Stack::operator==(const Stack& rhs) const {
	if (size_ != rhs.size_ || tos_ != rhs.tos_) return false;
	
	int i;
	for (i = 0; i < rhs.tos_; ++i)
		if (pArr_[i] != rhs.pArr_[i])
			break;
			
	return i == rhs.tos_;
}

void Stack::push(int data) {
	assert(size_ != tos_);
	pArr_[tos_] = data;
	++tos_;
}

int Stack::pop() {
	assert(tos_);
	--tos_;
	
	return pArr_[tos_];
}

int Stack::size() const {
	return size_;
}
