#include <stdio.h>
#include <stdlib.h> //for random function
#include <time.h>

int main(void)
{
	srand(time(NULL));  
	
	int i = 1;
	while(i <= 10){

		int dice = rand() % 6 + 1;
		printf("%d\n", dice);
		
		++i;
	}
	
	
	return 0;
}
