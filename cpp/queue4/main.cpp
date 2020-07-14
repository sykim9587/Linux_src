#include <iostream>
#include "queue.h"
//template

int main()
{
	Queue<int> q1;
	q1.push(100);
	q1.push(200);
	q1.push(300);
	
	std::cout << "q1 1st pop() : " << q1.pop() << std::endl;
	std::cout << "q1 2nd pop() : " << q1.pop() << std::endl;
	std::cout << "q1 3rd pop() : " << q1.pop() << std::endl;
	
	Queue<double> q2;
	q2.push(1.1);
	q2.push(2.2);
	q2.push(3.3);
	
	std::cout << "q2 1st pop() : " << q2.pop() << std::endl;
	std::cout << "q2 2nd pop() : " << q2.pop() << std::endl;
	std::cout << "q2 3rd pop() : " << q2.pop() << std::endl;
	
	return 0;
}
