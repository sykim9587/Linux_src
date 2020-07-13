#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"

class Queue{
private:
	static const int QUEUESIZE;
	int front_;
	int rear_;
	Array arr_;
public:
	explicit Queue(int size = Queue::QUEUESIZE);
	
	bool operator==(const Queue& rhs) const;
	
	int size()const;
	void push(int data); 
	int pop();	
};

#endif
