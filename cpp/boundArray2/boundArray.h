#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
#include "safeArray.h"

template <typename T>
class BoundArray: public SafeArray<T> {
private:
	int lower_;
	
public:
	BoundArray(int lower, int upper);
	BoundArray(int lower, int upper, T* pArr);
	
	bool operator==(const BoundArray<T>& rhs) const;
	
	T& operator[](int index);
	const T& operator[](int index) const;
	
	int lower() const;	//index
	int upper() const;

};

template <typename T>
BoundArray<T>::BoundArray(int lower, int upper)
:SafeArray<T>(upper-lower+1),lower_(lower)
{
	
}

template <typename T>
BoundArray<T>::BoundArray(int lower, int upper, T* pArr)
:SafeArray<T>(pArr + lower, upper-lower+1), lower_(lower)
{

}

template <typename T>
bool BoundArray<T>::operator==(const BoundArray<T>& rhs) const
{
	if(lower_ != rhs.lower_)
		return false;
	return SafeArray<T>::operator==(static_cast<SafeArray<T>>(rhs)); //slicing done. 
}

template <typename T>	
T& BoundArray<T>::operator[](int index)
{
	index -= lower_;
	return SafeArray<T>::operator[](index);
}

template <typename T>
const T& BoundArray<T>::operator[](int index) const
{
	index -=lower_;
	return SafeArray<T>::operator[](index);
}
	
template <typename T>
int BoundArray<T>::lower() const
{
	return lower_;
}

template <typename T>
int BoundArray<T>::upper() const
{
	return lower_+Array<T>::size_-1; //since it's protected member
}
#endif
