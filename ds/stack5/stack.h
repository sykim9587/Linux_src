#ifndef STACK_H
#define STACK_H


typedef struct stack{ 
	//int *pArr;
	void *pArr; // any data type can come
	int eleSize;
	int size;
	int tos;
}Stack;


void initStack(Stack* ps, int size, int eleSize);
void cleanupStack(Stack* ps);

void push(Stack* ps, const void *pData); //since pData value dosen't change, elesize is already set in struct
void pop(Stack* ps, void *pData); //it will change
#endif
