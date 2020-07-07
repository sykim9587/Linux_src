#include <iostream>
#include "complex.h"

int main()
{
	Complex c1;				//(0,0i)
	Complex c2(3.0);			//(3,0i)
	//Complex c2=3; Complex c2=3.0; => both possible
	Complex c3(3.0,4.0);	//(3,4i)
	Complex c4 = c3;       //complex c4(c3) -> copy constructor 
	Complex c5 = c3;
	
	//c1.real(c3.real());
	//c1.imag(c3.imag());
	c1 = c3; 					//operator=(c1,c2) or c1.operator = c3
	
	if (c1 == c3)				//operator== overloading! operator==(c1,c3) or c1.operator==(c2)
		std::cout<<"c1 and c3 are equal"<<std::endl;
	else
		std::cout<<"c1 and c3 are not equal"<<std::endl;
		
	c4 = c1+c2;			//c4.operator=(c1.operator+(c2)) //member function 
	c5 = c3-c2;

	std::cout << "c1: (" << c1.real() <<", "<<c1.imag() << "i)" << std::endl;
	std::cout << "c2: (" << c2.real() <<", "<<c2.imag() << "i)" << std::endl;
	std::cout << "c3: (" << c3.real() <<", "<<c3.imag() << "i)" << std::endl;
	std::cout << "c4: (" << c4.real() <<", "<<c4.imag() << "i)" << std::endl;
	std::cout << "c5: (" << c5.real() <<", "<<c5.imag() << "i)" << std::endl;	
	return 0;					//three destructors
}
