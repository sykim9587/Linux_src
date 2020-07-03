#ifndef STACK_H
#define STACK_H
#define STACKSIZE 100

typedef struct stack{ 
	int *pArr; //pointer for malloc
	int size;
	int tos;
}Stack;

void push(Stack* ps, int data);
int pop(Stack* ps);
void initStack(Stack* ps, int size);
void cleanupStack(Stack* ps);
#endif
