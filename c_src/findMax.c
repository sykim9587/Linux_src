#include <stdio.h>

int main(void)
{
	int nums[] = {30,40,100,90,10,60,20,70};
	
	int max = nums[0];
	for (int i=1; i<8; ++i){
		if (max < nums[i])
			max = nums[i];
			//printf("%d\n", max);
	}
	printf("max : %d\n", max);
	return 0;

}
