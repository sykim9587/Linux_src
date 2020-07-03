#include "qsort.h" //don't really need this since we didn't use structure
#include <stdio.h>
/*
void printnum(void *pArr, int arrSize){
	if(arrSize ==sizof(double)){
		for(int i=0; i<arrSize; i++){
			printf("%lf ",pArr[i]);
		}
		printf("\n");
	}
	
}

*/
static void swap(int *pa, int *pb)
{
	int tmp=*pa;
	*pa = *pb;
	*pb = tmp;
}


void qsort(int *pArr, int left, int right)
{

	printf("qsort(pArr, %d, %d)\n", left, right);
	if(left >= right)
		return;
		
	int last = left; //going to the num[0]
	for (int i=left+1; i<=right; ++i)
		if(pArr[left]>pArr[i]){ //if is in {} so it's one line
			++last;
			swap(pArr + last, pArr+i); //swap(&pArr[last], &pArr[i])
		}	
			
	
	swap(&pArr[left], &pArr[last]);
	qsort(pArr, left, last-1);
	qsort(pArr, last+1, right);
	
	
}

