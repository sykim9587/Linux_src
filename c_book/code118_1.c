#include <stdio.h>

int main(void){

	int res;
	
	res= sizeof(short)>sizeof(long);
	
	(res==1)? printf("short"):printf("long");
	// printf("%s\n", (res==1)? "short":"long");
	printf("\n");
	
	return 0;
}
