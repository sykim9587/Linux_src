#ifndef STACK_H
#define STACK_H
#define STACKSIZE 100

typedef struct stack{ 
	int arr[STACKSIZE];
	int tos;
}Stack;

void push(Stack* ps, int data);
int pop(Stack* ps);
void initStack(Stack* ps);

#endif
