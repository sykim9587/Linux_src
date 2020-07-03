#include <stdio.h>

int main(void)
{
	for (int i = 1; i <=5; ++i){
		for(int j = 1; j < 10; j++){
			if(j<=(5-i) || j >=(5+i))
				printf(" ");
			else
				printf("*");			
		}
		printf("\n");
	}	
	return 0;
}



/*
for(int j = 1; j<=5-i; ++j)
for(odd num) 
change line

*/
