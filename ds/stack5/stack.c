#include <string.h>
#include <assert.h> //assert 
#include "stack.h"
#include <stdlib.h> 


void push(Stack* ps, const void *pData)
{
	assert(ps->tos != ps->size);
	
	//ps->pArr[ps->tos] = data;
	//memcpy(&ps->pArr[ps->tos], pData, ps->eleSize); //addres address size
	memcpy((unsigned char*)ps->pArr + (ps->tos*ps->eleSize), pData, ps->eleSize); //for void pointer, unsigned char*
	++ps->tos;
}

void pop(Stack* ps, void *pData)
{
	assert(ps->tos); // !=0 can be skipped
	--ps->tos;
	
	//memcpy(pData, &ps->pArr[ps->tos], ps->eleSize);
	memcpy(pData, (unsigned char*) ps->pArr + ps->tos*ps->eleSize, ps->eleSize);
	//return ps->pArr[ps->tos];
}

void initStack(Stack* ps, int size, int eleSize)
{
	ps->pArr = malloc(eleSize*size);
	assert(ps -> pArr !=NULL); // !=NULL can be skipped
	ps->eleSize = eleSize;
	ps -> size = size;
	ps->tos =0;
}

void cleanupStack(Stack* ps){
	free(ps->pArr);
}
