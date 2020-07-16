#include <iostream>
#include "boundArray.h"

int main()
{
	int nums[] = {1,2,3,4,5,6,7,8,9,10};
	BoundArray<int> arr1(10,20); //index will be from 10 to 20
	BoundArray<int> arr2(2,7,nums); 
	BoundArray<int> arr3(arr2);
	
	arr1 == arr3;
	if (arr1 == arr3)
		std::cout<<"arr1 and arr3 are equal" <<std::endl;
	else
		std::cout <<"arr1 and arr3 are not equal"<<std::endl;
	
	for(int i=arr2.lower(); i<=arr2.upper(); ++i){
		std::cout<<arr2[i]<<std::endl;
	}
	
	
	return 0;
}

