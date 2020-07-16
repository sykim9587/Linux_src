#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
#include "safeArray.h"

class BoundArray: public SafeArray {
private:
	int lower_;
	
public:
	BoundArray(int lower, int upper);
	BoundArray(int lower, int upper, int* pArr);
	//BoundArray(const BoundArray& rhs);
	//~BoundArray();
	//BoundArray& operator=(const BoundArray& rhs);
	bool operator==(const BoundArray& rhs) const;
	
	int& operator[](int index);
	const int& operator[](int index) const;
	
	int lower() const;
	int upper() const;

};


#endif
