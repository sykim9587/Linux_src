#include <stdio.h>

int main(void)
{

	int fahr;
	float celsius;
	
	
	fahr = 100;
	celsius = 5.0/9.0 * (fahr-32);
	//celcius = 5/9*(fahr-32); is wrong, becomes 0 * ()
	
	printf("fahr: %d--> celsius: %f\n", fahr, celsius); 
	// d=decimal 
	

	return 0;
}
