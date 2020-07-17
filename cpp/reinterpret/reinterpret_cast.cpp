#include <stdio.h>

int main(void)
{
	int a = 0x12345678;
	char *p;
	
	//p = static_cast<char*>(&a); //doesn't work with static_cast
	p = reinterpret_cast<char*>(&a);	//now time to use this!
	
	
	printf("0x%x\n", *p); //little endian
	return 0;
}
