#ifndef QUEUE_H
#define QUEUE_H
#define STRUCTSIZE 100

typedef struct queue{
	int arr[STRUCTSIZE];
	int front;
	int rear;
}Queue;

void push(Queue* pq, int data);
int pop(Queue* pq);
void initStack(Queue* pq);


#endif


