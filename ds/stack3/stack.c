#include <stdio.h> //fprinf
#include <stdlib.h> // exit
#include "stack.h"

void push(Stack* ps, int data)
{
	if(ps->tos == STACKSIZE){
		fprintf(stderr, "stack is full\n"); //buffer usage difference (stdout: use buffer, stderr: no buffer)
		exit(1);
	}
	ps->arr[ps->tos] = data;
	++ps->tos;
}

int pop(Stack* ps)
{
	if(ps->tos == 0){
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	--ps->tos;
	return ps->arr[ps->tos];
}

void initStack(Stack* ps)
{
	ps->tos =0;
}
