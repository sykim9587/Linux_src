#include <stdlib.h> // malloc
#include <assert.h> 
#include "queue.h"
void initStack(Queue* pq, int size)
{
	pq->pArr = malloc(sizeof(int)*size);
	assert(pq->pArr);
	pq->front = 0;
	pq->rear = 0;
	pq->size = size;
}

void cleanupStack(Queue* pq){
	free(pq->pArr);
}

void push(Queue* pq, int data)
{

	assert(pq->front != (pq->rear + 1)%pq->size); //if rear=9, front = 0 then no more. to keep one space empty
	
	pq->pArr[pq->rear] = data;
	pq->rear = (pq->rear + 1)%pq->size; // to go back to the start	
}

int pop(Queue* pq)
{
	assert(pq->front != pq->rear); // same -> empty
	int index = pq->front;
	//++pq->front;
	pq->front = (pq->front+1)%pq->size;
	return pq->pArr[index];
}





