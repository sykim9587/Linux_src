#include <iostream>
#include "rational.h"

//using iostream, cin

int main()
{
	Rational r1(9,4);
	Rational r2(6,6);
	Rational r3(2,2);
	Rational r4 = r3;
	Rational r5; 			//	+
	Rational r6; 			//	-
	Rational r7; 			//	*
	Rational r8;			//	/
	
	r1=r3;
	r5=r2+r4;
	r6=r2-r4;
	r7=r2*r4;
	r8=r2/r4;
	
	std::cout << "input r4: ";
	std::cin >>r4;
	
	if (r2==r3) 
		std::cout<<"they are equal"<<std::endl;
	else
		std::cout<<"different"<<std::endl;
	
	const Rational r10(r1); //using copy constructor
	
	Rational *arr[5];
	for (int i=0; i<5; i++)
		arr[i]= new Rational;

	std::cout << "r1 is " << r1 << std::endl;
	std::cout << "r2 is " << r2 << std::endl;
	std::cout << "r3 is " << r3 << std::endl;
	std::cout << "r4 is " << r4 << std::endl;
	std::cout << "r5 is " << r5 << std::endl;
	std::cout << "r6 is " << r6 << std::endl;
	std::cout << "r7 is " << r7 << std::endl;
	std::cout << "r8 is " << r8 << std::endl;
	std::cout << "r10 is " << r10 << std::endl;
	
	std::cout << "# of Rational object : "<< Rational::getNumberofRational() << std::endl;

	for(int i=0; i<5; i++)
		delete arr[i];

	std::cout << "# of Rational object : "<< Rational::getNumberofRational() << std::endl;

	return 0;
}
