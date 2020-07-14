#include <iostream>
#include "array.h"
#include "safeArray.h"
//using inheritance

int main()
{
	int nums[] = {1,2,3,4,5};
	Array arr1(nums, 5);
	
	for(int i=0; i<= arr1.size(); ++i)
		std::cout<<arr1[i]<< " ";
	std::cout<<std::endl;
	
	SafeArray arr3;
	SafeArray arr4(10);
	SafeArray arr5(arr4);
	
	//this is using safeArray, with boundary check 
	SafeArray arr(nums, 5);
	for(int i=0; i<= arr.size(); ++i)
		std::cout<<arr[i]<< " ";
	std::cout<<std::endl;
	
	return 0;
}
