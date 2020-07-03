#include <stdio.h>
#include "qsort.h"

int main(void)
{
	int nums[] = {3,4,6,1,2,7,9,10,8,5};
	qsort(nums, 0,10-1);
	
	for(int i=0; i<10; ++i)
		printf("%d ", nums[i]);
	printf("\n");
	return 0;
	
}
