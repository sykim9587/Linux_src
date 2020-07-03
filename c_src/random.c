#include <stdio.h>
#include <stdlib.h> //for random function
#include <time.h>

int main(void)
{
	srand(time(NULL));   //seed
	
	int i = 1;
	while(i <= 10){
		//printf("%d\n", i); 
		int num = rand(); // decimal is created
		printf("%d\n", num);
		
		
		
		++i; //i = i+1;
	}
	
	
	return 0;
}
