#include <assert.h> //assert 
#include "stack.h"
#include <stdlib.h> 

void push(Stack* ps, int data)
{
	assert(ps->tos != ps->size);
	ps->pArr[ps->tos] = data;
	++ps->tos;
}

int pop(Stack* ps)
{
	assert(ps->tos); // !=0 can be skipped
	--ps->tos;
	return ps->pArr[ps->tos];
}

void initStack(Stack* ps, int size)
{
	ps->pArr = malloc(sizeof(int)*size);
	assert(ps -> pArr !=NULL); // !=NULL can be skipped
	ps -> size = size;
	ps->tos =0;
}

void cleanupStack(Stack* ps){
	free(ps->pArr);
}
