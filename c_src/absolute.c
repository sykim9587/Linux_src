#include <stdio.h>

int main(void){

	int num;
	printf("input value: ");
	scanf("%d", &num);
	
	if(num<0){
		num*=-1;
	}
	printf("absolute value: %d\n", num);
	return 0;
}
