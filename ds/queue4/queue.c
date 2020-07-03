#include <stdlib.h> // malloc
#include <assert.h> 
#include "queue.h"

void cleanupStack(Queue* pq){
	free(pq->pArr);
}

void push(Queue* pq, int data)
{
	assert(pq->rear != pq->size);
	pq->pArr[pq->rear] = data;
	++pq->rear;		
}

int pop(Queue* pq)
{
	assert(pq->front != pq->rear);
	return pq->pArr[(pq->front)++];
}

void initStack(Queue* pq, int size)
{
	pq->pArr = malloc(sizeof(int)*size);
	assert(pq->pArr);
	pq->front = 0;
	pq->rear = 0;
	pq->size = size;
}



