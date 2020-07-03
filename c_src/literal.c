#include <stdio.h>

int main(void)
{
	printf("%d %d %d\n", 100, 0144, 0x64);	//decimal 
	printf("%d 0%o 0x%x\n", 100, 100, 100); 	//octal(8), hexa-decimal(16) - format 0, 0x 

	printf("%d %d %d\n", 'A', 'a', '0');	//65 97 48
	printf("%d %d %d\n", 65, 97, 48);	//65 97 48
	
	printf("%c %c %c\n", 65, 97, 48);		//character 
	printf("%c %c %c\n", 'A', 'a','0');
	
	printf("%c %c %c\n", 'A', 'A'+1,'A'+2);
	
	printf("%f %f\n", 3.1415,2.718F);
	
	printf("%s\n", "ABCD"); 
	printf("%lldLL\n", 10000000000LL);		//long long
	return 0;
}
