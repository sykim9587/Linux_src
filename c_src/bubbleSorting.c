#include <stdio.h>

int main(void)
{
	int nums[] = {30,40,100,90,10,60,20,70,50,80};

	for(int i =9; i>=1; --i){
		for(int j=0; j<i; ++j){
			if (nums[j]>nums[j+1]){
				int tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}
	
	for(int i=0; i<10; i++)
		printf("%d ", nums[i]);
	printf("\n");
	return 0;

}
