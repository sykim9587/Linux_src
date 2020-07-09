#include <iostream>
#include "array.h"

int main()
{
	Array arr1;
	Array arr2(10);
	int nums[] = {1,2,3,4,5};
	const Array arr3(nums, 5);
	Array arr4 = arr3;
	
	arr1 = arr3;

	if( arr1 == arr3 )
		std::cout<< "arr1 and arr3 are equal" << std::endl;
	else
		std::cout <<"different" <<std::endl;
		
	//arr3[0] = 1; //const int reference is leftside and right side is int. = not allowed.
	
	
	for (int i=0; i<arr1.size(); ++i)
		std::cout<<arr1[i]<<" ";				//arr1.operator[](i)
	std::cout<<std::endl;
		
	return 0;
}
