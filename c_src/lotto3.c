#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int lotto[45];				//generating array
	srand(time(NULL));
	
	for (int i=0; i<45; ++i){	//filling in 
		lotto[i] = i+1;
	}
	
	int k=1;
	while(k<1000000){			//swapping 
		swap(&lotto[rand()%45], &lotto[rand()%45]);
		++k;
	}
	
	for (int i =0; i<7; ++i)	//printing
		printf("%d ", lotto[i]);
	
	printf("\n");
	return 0;
}
