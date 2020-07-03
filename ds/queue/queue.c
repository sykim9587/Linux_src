#include <stdio.h>
#include <ctype.h>

int queue[100];
int front;
int rear;

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

int main(void)
{
	push(100);
	push(200);
	
	printf("1st pop(): %d\n", pop());
	
	push(300);
	printf("2nd pop(): %d\n", pop());
	printf("3rd pop(): %d\n", pop());
	
	printf("what is %d\n",isdigit('a'));
	
	return 0;
}
