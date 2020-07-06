#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
	double re;	//real
	double im;	//imaginary
public:
	Complex();							//defualt constructor
	Complex(double re);					//convert constructor : double becomes complex
	Complex(double re, double im);	//ordinary constructor
	
	~Complex();							//destructor 
	
	//get value
	double real();
	double imag();
	
	//set value -> setReal setImag
	void real(double re);
	void imag(double im); 
};

#endif
