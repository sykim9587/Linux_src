#include <cassert> //assert using namespace in cpp
#include <cstddef>
#include "stack.h"
//#include <stdlib.h> 

Stack::Stack(int size) //constructor
{
	//this->pArr = (int*)malloc(sizeof(int)*size);
	this->pArr = new int[size]; 
	
	assert(this-> pArr !=NULL); // !=NULL can be skipped
	this-> size = size;
	this->tos =0;
}

Stack::~Stack(){ // void not necessary, destructor
	//free(this->pArr);
	delete [] this->pArr;
}

void Stack::push(int data)
{
	assert(this->tos != this->size);
	this->pArr[this->tos] = data;
	++this->tos;
}

int Stack::pop()
{
	assert(this->tos); // !=0 can be skipped
	--this->tos;
	return this->pArr[this->tos];
}


