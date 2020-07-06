#include <iostream>
#include <stdlib.h> //malloc and NULL
#include "queue.h"

//fourth queue -> assert,malloc
int main()
{
	Queue q1(10), q2(100);
	
	
	q1.push(100);
	q1.push(200);
	q1.push(300);

	std::cout<< "q1 1st pop(): "<<q1.pop()<<std::endl;
	std::cout<< "q1 2nd pop(): "<<q1.pop()<<std::endl;
	std::cout<< "q1 3rd pop(): "<<q1.pop()<<std::endl;	
	
	q2.push(500);
	q2.push(600);
	q2.push(700);	

	
	std::cout<< "q2 1st pop(): "<<q2.pop()<<std::endl;
	std::cout<< "q2 2nd pop(): "<<q2.pop()<<std::endl;
	std::cout<< "q2 3rd pop(): "<<q2.pop()<<std::endl;

	return 0;
}
