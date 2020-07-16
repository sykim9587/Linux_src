#include <iostream>
#include "array.h"
#include "safeArray.h"
//using inheritance

int main()
{
	int nums[] = {1,2,3,4,5};
	Array arr1(nums, 5);
	
	for(int i=0; i< arr1.size(); ++i)
		std::cout<<arr1[i]<< " ";
	std::cout<<std::endl;
	
	SafeArray arr3;
	SafeArray arr4(10);
	SafeArray arr5(arr4);
	
	//this is using safeArray, with boundary check 
	SafeArray arr(nums, 5);
	
	for(int i=0; i< arr.size(); ++i)
		std::cout<<arr[i]<< " ";
	std::cout<<std::endl;
	
	Array *pArr = new SafeArray(arr); //super class pointer can point sub class pointer (also reference too!) = polymorphism
	pArr->operator[](5) = 10; //(*pArr)[5] = 10; //static binding (during compile time. default)

	delete pArr; //destructor + free (default would be Array when the object is safearray)
	return 0;
}
