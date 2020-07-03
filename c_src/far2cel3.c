#include <stdio.h>

int main(void)
{
	int fahr;
	int celsius,cel1, cel2,cel3;
	
	fahr=100;
	celsius = 5*1000* (fahr-32)/9;
	cel1=celsius/1000;
	cel2=(celsius-cel1*1000)/10;
	cel3=(celsius-cel1*1000-cel2*10)/5;
	
	/*
	right = (777+5)/10; add 5 and then divide it by 10 
	*/
	
	
	printf("fahr: %d--> celsius: %d.%d\n", fahr, cel1,cel2+cel3); 
	
	return 0;
}



