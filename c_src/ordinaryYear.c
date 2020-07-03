#include <stdio.h>

int main(void)
{
	int year;
	printf("intput year : ");
	scanf("%d", &year);
	
	//if(!(year%4==0 && year%100!=0 || year%400==0 )){
	if(year % 4 !=0 || year%100 ==0 && year %400 != 0){
		printf("ordinary\n");
	}
	else{
		printf("leap\n");
	}

	
	return 0;
}
