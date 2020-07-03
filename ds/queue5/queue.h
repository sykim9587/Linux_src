#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
	void *pArr;
	int front;
	int rear;
	int size;
	int eleSize;
}Queue;

void push(Queue* pq, const void *pData);
void pop(Queue* pq, void *pData);

void initStack(Queue* pq, int size, int eleSize);
void cleanupStack(Queue* pq);

#endif


