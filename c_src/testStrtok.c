#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "aaa bbb ccc\tddd\nfff";
	
	char *token = strtok(str, " ");
	
	
	do{
		printf("%s\n", token);
	}while(token = strtok(NULL, " "));
	return 0;
}
