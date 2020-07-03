#include <stdio.h>

int main(void)
{
	int nums[] = {30,40,100,90,10,60,20,70};
	
	int num;
	printf("input value: ");
	scanf("%d", &num);
	int i;
	for(i = 0; i<10; ++i){
		if(num == nums[i]) break;
	}
	
	if(i<10)
		printf("found at index : %d\n", i);
	else
		printf("not found\n");
	return 0;

}
