#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

template <typename T>
class SafeArray : public Array<T>{ //Array: parent. parent's public goes to child's public
private:
	static const int SAFE_ARRAY_SIZE;

public:
	explicit SafeArray(int size = SafeArray<T>::SAFE_ARRAY_SIZE);
	SafeArray(const T *pArr, int size);
	SafeArray(const SafeArray<T>& rhs);
	virtual ~SafeArray();
	SafeArray<T>& operator=(const SafeArray<T>& rhs);

	bool operator==(const SafeArray<T>& rhs) const;
	
	virtual T& operator[](int index);
	virtual const T& operator[](int index) const;
};

#include <cassert>
template <typename T>
const int SafeArray<T>::SAFE_ARRAY_SIZE = 100;

template <typename T>
SafeArray<T>::SafeArray(int size)
: Array<T>(size)
{
//get Array constructor
}

template <typename T>
SafeArray<T>::SafeArray(const SafeArray<T>& rhs)
:Array<T>((Array<T>)rhs)
{
//slicing. typecasting the SafeArray to rhs.
}

template <typename T>
SafeArray<T>::SafeArray(const T *pArr, int size)
:Array<T>(pArr,size)
{
	
}

template <typename T>
SafeArray<T>::~SafeArray()
{
//automatically getting Array destructor
}

template <typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& rhs)
{
	this->Array<T>::operator=((Array<T>)rhs); //type casting
	//if there are more memeber variable for SafeArray, add here. 
	return *this;
}

template <typename T>	
bool SafeArray<T>::operator==(const SafeArray<T>& rhs) const
{
	return this->Array<T>::operator==((Array<T>)rhs);
}

template <typename T>	
T& SafeArray<T>::operator[](int index) //typical class inheritance
{
	assert(index >=0 && index< this->Array<T>::size_); //using protected keyword, subcalss memeber can approach super private member.
	return this->Array<T>::operator[](index);
}

template <typename T>
const T& SafeArray<T>::operator[](int index) const
{
	assert(index >=0 && index< this->Array<T>::size_);
	return this->Array<T>::operator[](index);
}

#endif 
