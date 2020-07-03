#include <stdio.h>
#include "qsort.h"
#include "stack.h"

int main(void)
{
	int nums[] = {3,4,6,1,2,7,9,10,8,5};
	double nums1[] = {2.2, 3.3, 1.1, 5.5, 8.8, 4.4, 6.6,9.9,7.7};
	
	
	printf("Before sorting\n");
	printDouble(nums1, sizeof(nums1)/sizeof(nums1[0]));
	printInt(nums, sizeof(nums)/sizeof(nums[0]));
	
	
	int e=(sizeof(nums1)/sizeof(nums1[0]))-1; //e = number of elements -1
	qsortgen(nums1, 0,e,sizeof(nums1[0]));

	e=(sizeof(nums)/sizeof(nums[0]))-1;
	qsortgen(nums, 0,e,sizeof(nums[0]));
	
	
	printf("After sorting\n");
	printDouble(nums1, sizeof(nums1)/sizeof(nums1[0]));
	printInt(nums, sizeof(nums)/sizeof(nums[0]));
	
	return 0;	
}


