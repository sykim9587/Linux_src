#include <stdio.h>

//first stack!


//global variable -> initialize as 0
int stack[100];
int tos =-1; // top of stack

void push(int data)
{
	++tos;
	stack[tos] = data;
	
}

int pop(void)
{
	int index = tos;
	--tos;
	return stack[index]; //tos --
}

int main(void)
{
	push(100);
	push(200);
	push(300);
	
	printf("1st pop(): %d\n", pop());
	printf("2nd pop(): %d\n", pop());
	printf("3rd pop(): %d\n", pop());	

	return 0;
}
