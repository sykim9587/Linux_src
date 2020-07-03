#include "serial.h" //not necessary but should write it

//int count = 1; //global

int getSerialNumber(void)
{
	//int count = 1; => local 
	static int count = 1; //only used in this function so not global & but stayed over the program
	
	return count++;
}
