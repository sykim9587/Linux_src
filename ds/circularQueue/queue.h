#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
	int* pArr;
	int front;
	int rear;
	int size;
}Queue;

void push(Queue* pq, int data);
int pop(Queue* pq);

void initStack(Queue* pq, int size);
void cleanupStack(Queue* pq);

#endif


