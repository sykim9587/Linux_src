#include <stdio.h> //fprinf
#include <stdlib.h> // exit
#include "queue.h"

void push(Queue* pq, int data)
{
	if(pq->rear == STRUCTSIZE){
		fprintf(stderr, "stack is full\n");
		exit(1);
	}
	pq->arr[pq->rear] = data;
	++pq->rear;
		
}

int pop(Queue* pq)
{
	if(pq->front == pq->rear){
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	return pq->arr[(pq->front)++];
}

void initStack(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

