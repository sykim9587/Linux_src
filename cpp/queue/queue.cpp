#include <stdlib.h> // malloc
#include <cassert> 
#include "queue.h"

Queue::~Queue()
{
	delete [] this->pArr;
}

Queue::Queue(int size)
{
	this->pArr = new int[size];
	assert(this->pArr);
	this->front = 0;
	this->rear = 0;
	this->size = size;
}

void Queue::push(int data)
{
	assert(this->rear != this->size);
	this->pArr[this->rear] = data;
	++this->rear;		
}

int Queue::pop()
{
	assert(this->front != this->rear);
	return this->pArr[(this->front)++];
}





