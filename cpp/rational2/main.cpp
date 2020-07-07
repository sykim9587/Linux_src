#include <iostream>
#include "rational.h"

int main()
{
	Rational r1;
	Rational r2(3);
	Rational r3(3,4);
	Rational r4 = r3;
	Rational r5; //+
	Rational r6; //-
	Rational r7; //*
	Rational r8;	///
	
	
	std::cout << "using default arguments r1: " << r1.getNum() <<"/"<<r1.getDen() << std::endl;
	
	r1=r3;
	r5=r2+r4;
	r6=r2-r4;
	r7=r2*r4;
	r8=r2/r4;
	
	std::cout << "using operator= (r1=r3) r1: " << r1.getNum() <<"/"<<r1.getDen() << std::endl;
	std::cout << "using default arguments r2: " << r2.getNum() <<"/"<<r2.getDen() << std::endl;
	std::cout << "ordinary constructor r3: " << r3.getNum() <<"/"<<r3.getDen() << std::endl;
	std::cout << "using copy constructor(r4=r3) r4: " << r4.getNum() <<"/"<<r4.getDen() << std::endl;	
	std::cout << "using operator+ (r2+r4) r5: " << r5.getNum() <<"/"<<r5.getDen() << std::endl;
	std::cout << "using operator- (r2-r4) r6: " << r6.getNum() <<"/"<<r6.getDen() << std::endl;
	std::cout << "using operator* (r2*r4) r7: " << r7.getNum() <<"/"<<r7.getDen() << std::endl;
	std::cout << "using operator/ (r2/r4) r8: " << r8.getNum() <<"/"<<r8.getDen() << std::endl;
	if(r1==r3) 
		std::cout << "r1 and r3 are equal" << std::endl;	
	else
		std::cout << "r1 and r3 are not equal" << std::endl;
	return 0;
}
