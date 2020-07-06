#ifndef STACK_H
#define STACK_H
#define STACKSIZE 100

class Stack{ 
private:	
	int *pArr; 
	int size;
	int tos;
	
public:
	void push(int data);
	int pop();
	
	Stack(int size); //no return value, this is constructor
	~Stack(); //destructor 
	
};


#endif
