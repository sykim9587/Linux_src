#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

class SafeArray : public Array{ //Array: parent. parent's public goes to child's public
private:
	static const int SAFE_ARRAY_SIZE;

public:
	explicit SafeArray(int size = SafeArray::SAFE_ARRAY_SIZE);
	SafeArray(const int *pArr, int size);
	SafeArray(const SafeArray& rhs);
	virtual ~SafeArray();
	SafeArray& operator=(const SafeArray& rhs);

	bool operator==(const SafeArray& rhs) const;
	
	//to use dynamic binding 
	virtual int& operator[](int index);
	virtual const int& operator[](int index) const;
};

#endif 
