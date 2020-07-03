#include "qsort.h" //don't really need this since we didn't use structure
#include <stdio.h>
#include "stack.h"
static void swap(int *pa, int *pb)
{
	int tmp=*pa;
	*pa = *pb;
	*pb = tmp;
}


void qsort(int *pArr, int left, int right)
{

	
	push(right);
	push(left);
	
	while(!isEmpty()){
		
		int start = pop(); //left
		int end = pop(); 
		printf("start: %d\tend: %d\n", start, end);
		int last =start;
		for(int i = start+1; i<=end; ++i)
			if(pArr[start]>pArr[i]){
				++last;
				swap(pArr+last, pArr+i);
			}
		swap(&pArr[start], &pArr[last]);
		
		if(start<end){
			push(end);
			push(last+1);
			push(last-1);
			push(start);
		}
		
	}
	
	
}

