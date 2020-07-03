#include <stdio.h>
#include "qsort.h"
int main(void)
{
	int nums[] = {3,4,6,1,2,7,9,10,8,5};
	//int nums1[] = {3.3, 2.2, 5.5, 1.1};
	qsort(nums, 0,10-1);
	
	for(int i=0; i<10; ++i)
		printf("%d ", nums[i]);
	printf("\n");
	
	//printnum(nums1, sizeof(nums1[0]);
	return 0;
	
}
