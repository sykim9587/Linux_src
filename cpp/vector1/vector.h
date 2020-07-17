#ifndef VECTOR_H
#define VECTOR_H

template<class T, int N>
class Vector {
private: 
	T *begin, *end;
public:
	Vector();
	Vector(const Vector<T,N>& rhs);
	~Vector();	
	T& operator[] (int n);
	Vector<T,N>& operator= (const Vector<T,N>& rhs);
	Vector<T,N>& operator+=(const Vector<T,N>& rhs);
	Vector<T,N> operator+(const Vector<T,N>& rhs);
};

template<class T, int N>
Vector<T,N>::Vector()
:begin(new T[N]), end(begin+N)
{

}

template<class T, int N> 
Vector<T,N>::Vector(const Vector<T,N>& rhs) //copy constructor
:begin(new T[N]), end(begin+N)
{
	T* dest = begin;
	T* src = rhs.begin;
	while(src != rhs.end) *dest++ = *src++;
}

template<class T, int N>
Vector<T,N>::~Vector()
{
	delete [] begin;
}

template<class T, int N>	
T& Vector<T,N>::operator[] (int n)
{
	return begin[n];
}

template<class T, int N>
Vector<T,N>& Vector<T,N>::operator= (const Vector<T,N>& rhs) //assignment operator
{
	if(&rhs == this) return *this;
	T* dest = begin;
	T* src = rhs.begin;
	while(src != rhs.end) *dest++=*src++;
	return *this;

}

template<class T, int N>
Vector<T,N>& Vector<T,N>::operator+=(const Vector<T,N>& rhs)
{
	T* dest = begin;
	T* src = rhs.begin;
	while(dest!=end) *(dest++) += *(src++);
	return *this;
}

template<class T, int N>
Vector<T,N> Vector<T,N>::operator+(const Vector<T,N>& rhs)
{
	return Vector<T,N>(*this) += rhs;
}

#endif
