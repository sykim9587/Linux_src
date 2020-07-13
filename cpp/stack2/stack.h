#ifndef STACK_H
#define STACK_H

class Stack {
private:
	static const int STACKSIZE;

	int* pArr_;
	int size_;
	int tos_;

	void set_arr(const int* pArr, int size, int tos = 0);
public:
	explicit Stack(int size = Stack::STACKSIZE);
	Stack(const int* pArr, int size, int tos);
	Stack(const Stack& rhs);
	~Stack();
	
	Stack& operator=(const Stack& rhs);
	
	bool operator==(const Stack& rhs) const;
	
	void push(int data);
	int pop();
	
	int size() const;
};

#endif

