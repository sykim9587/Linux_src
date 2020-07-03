#include <stdio.h>
#define BOLD 		(0x01 <<0)
#define ITALIC 	(0x01 <<1)
#define SHADOW 	(0x01 <<2)
#define UL	 	(0x01 <<3)
int main(void)
{
	unsigned char attr; //bit has meaning
	
	attr = attr ^ attr; //attr = 0;
	attr = attr | BOLD; //bold 
	attr = attr | (ITALIC + UL); //ITALIC + UL wrong! (after shifting)
	
	attr = attr & ~BOLD; //erase bold
	
	printf("attr : 0x%02x\n", attr);

	return 0;
}
