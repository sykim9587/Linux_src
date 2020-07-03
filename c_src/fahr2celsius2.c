#include <stdio.h>

int main(void)
{
	int fahr;
	double celsius; //double floating-point number - using 8 bytes
	
	printf("input fahr temp: ");
	scanf("%d", &fahr);
	//fahr = 100;
	celsius = 5.0/9.0 * (fahr-32);
	
	printf("fahr: %d--> celsius: %.2f\n", fahr, celsius); 
	// d=decimal f=floating point
	

	return 0;
}
