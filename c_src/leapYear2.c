#include <stdio.h>

int main(void)
{
	int year;
	printf("intput year : ");
	scanf("%d", &year);
	
/*	if(year%4==0 && year%100!=0 || year%400==0 ){
	//if((year%400==0 || year%4==0 && year%100!=0)){
		printf("leap\n");
	}
	else{
		printf("ordinary\n");
	}
*/
	printf("%d is a %s year\n", year, 
	(year%400==0 || year%4==0 && year%100!=0)? "leap": "ordinary");
	
	return 0;
}
