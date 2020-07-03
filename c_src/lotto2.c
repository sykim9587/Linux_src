#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int lotto[7];
	srand(time(NULL));
	for(int i=0; i<7; i++){	
		lotto[i] = rand()%45+1;
		for(int j=0; j<i; j++){
			if(lotto[j]==lotto[i]){
				i-=1;break;
			}
			if(j==(i-1)) printf("%d ",lotto[i]);
		}
	}
	printf("\n");
	return 0;
}





