#include <stdio.h>

int main(void)
{
	int num[] = {50,60,10,100,30,40};
	int max = num[0];
	int size = sizeof(num)/sizeof(num[0]);
	for(int i = 1; i < size; i++){
		if(num[i]>max){
			max = num[i];
		}
	}
	printf("max = %d\n", max);
	
	return 0;
}
