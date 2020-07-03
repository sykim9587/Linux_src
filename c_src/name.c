#include <stdio.h>

int main(void)
{
	char name[20];
	scanf("%19s", name);	//scanf("%s", &name[0]); until \0
	printf("%s\n", name);
	
	printf("%s\n", "hello, world" +2); //from l 
	return 0;
}
