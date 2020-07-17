#include <iostream>
#include "array.h"
#include "safeArray.h"
#include "invalidIndex.h"
//Exception handling - try throw catch

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
	SafeArray arr6(nums, 5);
	
	for(int i=0; i< arr6.size(); ++i)
		std::cout<<arr6[i]<< " ";
	std::cout<<std::endl;

	try{ //choose code that had assert	
		Array *pArr = new SafeArray(arr6); 	
		(*pArr)[5] = 10; //static binding (during compile time. default)	
		int tmp = (*pArr)[5];
		std::cout<<tmp<<std::endl;
		delete pArr;
	} catch (const InvalidIndex &r){
		std::cerr <<"boundary exeption is occurred, at : "<< r.getInvalidIndex() <<std::endl;
		return 1;
	}
		

	return 0;
}
