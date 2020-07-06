#ifndef QUEUE_H
#define QUEUE_H

class Queue{
private:
	int* pArr;
	int front;
	int rear;
	int size;
public:
	void push(int data);
	int pop();

	Queue(int size);
	~Queue();
};

#endif
