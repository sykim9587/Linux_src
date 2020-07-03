#include <string.h> //memcpy
#include <assert.h> 
#include <stdlib.h> 
#include "queue.h"

void cleanupStack(Queue* pq){
	free(pq->pArr);
}

void push(Queue* pq, const void *pData)
{
	assert(pq->rear != pq->size);

	memcpy((unsigned char*)pq->pArr + (pq->rear*pq->eleSize), pData, pq->eleSize);
	++pq->rear;		
}

void pop(Queue* pq, void *pData)
{
	assert(pq->front != pq->rear);
	memcpy(pData, (unsigned char*)pq->pArr + (pq->front*pq->eleSize), pq->eleSize);
	pq->front++;
}

void initStack(Queue* pq, int size, int eleSize)
{
	pq->pArr = malloc(eleSize*size);
	assert(pq->pArr != NULL);
	pq->front = 0;
	pq->rear = 0;
	pq->eleSize = eleSize;
	pq->size = size;
}



