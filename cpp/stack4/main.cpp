#include <iostream>
#include "stack.h"
//template 
int main()
{
	Stack<int> s1;
	s1.push(100);
	s1.push(200);
	s1.push(300);
	
	std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
	std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
	std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;
	
	Stack<double> s2;
	s2.push(1.1);
	s2.push(2.2);
	s2.push(3.3);
	
	std::cout << "s2 1st pop() : " << s2.pop() << std::endl;
	std::cout << "s2 2nd pop() : " << s2.pop() << std::endl;
	std::cout << "s2 3rd pop() : " << s2.pop() << std::endl;
	
	return 0;
}

