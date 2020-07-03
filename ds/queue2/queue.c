static int queue[100];
static int front;
static int rear;
//only push and pop can approach
void push(int data)
{
	queue[rear] = data;
	++rear;
		
}

int pop(void)
{
	//int index = front; ++front;
	return queue[front++];
}


