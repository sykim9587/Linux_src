#include "qsort.h" //don't really need this since we didn't use structure
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>


static void swap(void *pa, void *pb, int eleSize)
{
	void *tmp = malloc(eleSize);
	memcpy(tmp,pa,eleSize);
	memcpy(pa,pb,eleSize);
	memcpy(pb,tmp,eleSize);
}

int pointcompare(void* startp, void* ip, int eleSize){	
	if (eleSize==sizeof(int)){
		//printf("comparing %d %d\n",*(int*)startp,*(int*)ip);
		return (*(int*)startp)>(*(int*)ip);
	}
	else{
		//printf("comparing %lf %lf\n",*(double*)startp,*(double*)ip);
		return (*(double*)startp)>(*(double*)ip);
	}	
}

void qsortgen(void *pArr, int left, int right, int eleSize)
{	
	//printf("now %d size\n",eleSize);
	push(right);
	push(left);
	//printf("%lf\n",*(double*)pArr);
	
	while(!isEmpty()){
		
		int start = pop(); //left
		int end = pop(); 
		//printf("start: %d\tend: %d\n", start, end);
		int last =start;
		for(int i = start+1; i<=end; ++i)
			if(pointcompare((unsigned char*)pArr+start*eleSize,(unsigned char*)pArr+i*eleSize,eleSize)){
				++last;
				swap((unsigned char*)pArr+last*eleSize, (unsigned char*)pArr+i*eleSize, eleSize);
			}
		swap((unsigned char*)pArr+start*eleSize, (unsigned char*)pArr+last*eleSize,eleSize);
		
		if(start<end){
			push(end);
			push(last+1);
			push(last-1);
			push(start);
		}
		
	}
}


void printInt(const int *pData, int size)
{
	for(int i=0; i<size; i++){
			printf("%d ", pData[i]);
	}
	printf("\n");
}

void printDouble(const double *pData, int size)
{
	
	for(int i=0; i<size; i++){
			printf("%.1lf ",pData[i]);
	}
	printf("\n");
}

