#ifndef STACK_H
#define STACK_H
#include "array.h"

template <typename T>
class Stack {
private:
	static const int STACKSIZE;

	Array<T> arr_;
	int tos_;

	//void set_arr(const int* pArr, int size, int tos = 0);
public:
	explicit Stack(int size = Stack<T>::STACKSIZE);
	//Stack(const int* pArr, int size, int tos);

	bool operator==(const Stack<T>& rhs) const;
	
	int size() const;
	const T pop();
	void push(const T& data);	 //if complex type class comes 

};

#include <cassert>
template <typename T>
const int Stack<T>::STACKSIZE = 100;

template <typename T>
Stack<T>::Stack(int size)
: arr_(size), tos_(0)
{

}

template <typename T>
bool Stack<T>::operator==(const Stack<T>& rhs) const
{
	if (tos_ != rhs.tos_) return false;
	
	return arr_ == rhs.arr_;
}

template <typename T>
int Stack<T>::size() const
{
	return arr_.size();
}

template <typename T>
void Stack<T>::push(const T& data)
{
	assert(tos_ != size());
	arr_[tos_] = data;
	++tos_;
}

template <typename T>
const T Stack<T>::pop()
{
	assert(tos_);
	--tos_;
	return arr_[tos_];
}

#endif

