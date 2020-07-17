#include "safeArray.h"
#include <cassert>

const int SafeArray::SAFE_ARRAY_SIZE = 100;

SafeArray::SafeArray(int size)
: Array(size)
{
//get Array constructor
}


SafeArray::SafeArray(const SafeArray& rhs)
:Array(static_cast<Array>(rhs))
{
//slicing. typecasting the SafeArray to rhs.
}

SafeArray::SafeArray(const int *pArr, int size)
:Array(pArr,size)
{
	
}

SafeArray::~SafeArray()
{
//automatically getting Array destructor
}

SafeArray& SafeArray::operator=(const SafeArray& rhs)
{
	this->Array::operator=(static_cast<Array>(rhs)); //type casting
	//if there are more memeber variable for SafeArray, add here. 
	return *this;
}
	
bool SafeArray::operator==(const SafeArray& rhs) const
{
	return this->Array::operator==(static_cast<Array>(rhs));
}
	
int& SafeArray::operator[](int index) //typical class inheritance
{
	assert(index >=0 && index< this->Array::size_); //using protected keyword, subcalss memeber can approach super private member.
	return this->Array::operator[](index);
}


const int& SafeArray::operator[](int index) const
{
	assert(index >=0 && index< this->Array::size_);
	return this->Array::operator[](index);
}
