#include <stdio.h>

int main(void)
{
	int num;
	printf("input num: ");
	scanf("%d", &num);
	
	if(num>0)
		printf("%d is positive number\n",num);
	else if(num < 0)
		printf("%d is a negative number\n", num);
	else
		printf("zero\n");
		
	printf("num %d is a %s number\n", num, (num>0)?"positive":(num=0)?"zero":"negative");

	return 0;
}
