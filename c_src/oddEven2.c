#include <stdio.h>

int main(void)
{
	int num;
	printf("Input num: ");
	scanf("%d", &num);
	
//	if(num%2)
//		printf("odd num\n");
//	else
//		printf("even num\n");

	printf("%d is %s num\n",num, (num % 2 )? "odd": "even");
		
	return 0;
}

