#include <iostream>
#include "stack.h"

int main()
{
	Stack s1;
	Stack s2(10);
	Stack s3(s2);
	
	s2.push(100);
	s2.push(200);
	s2.push(300);
	
	s1 = s2;
	if (s1 == s2)
		std::cout << "s1 and s2 are equal" << std::endl;
	else
		std::cout << "s1 and s2 are not equal" << std::endl;
	
	std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
	std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
	std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;
	
	return 0;
}

