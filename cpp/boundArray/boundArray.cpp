#include "boundArray.h"
BoundArray::BoundArray(int lower, int upper)
:SafeArray(upper-lower+1),lower_(lower)
{
	
}


BoundArray::BoundArray(int lower, int upper, int* pArr)
:SafeArray(pArr + lower, upper-lower+1), lower_(lower)
{

}

bool BoundArray::operator==(const BoundArray& rhs) const
{
	if(lower_ != rhs.lower_)
		return false;
	return SafeArray::operator==(static_cast<SafeArray>(rhs)); //slicing done. 
}
	
int& BoundArray::operator[](int index)
{
	index -= lower_;
	return SafeArray::operator[](index);
}
const int& BoundArray::operator[](int index) const
{
	index -=lower_;
	return SafeArray::operator[](index);
}
	
int BoundArray::lower() const
{
	return lower_;
}

int BoundArray::upper() const
{
	return lower_+size_-1; //since it's protected member
}
