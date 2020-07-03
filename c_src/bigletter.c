#include <stdio.h>

int main(void)
{	
	char ch;
	printf("input char : ");
	scanf("%c", &ch);
	
	if(ch>='A' && ch <='Z')
		printf("ch: %c is capital\n",ch);
	
	return 0;
}
