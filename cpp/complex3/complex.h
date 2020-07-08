#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex;
std::ostream& operator<<(std::ostream& out, const Complex& rhs);//cout is a class in std::ostream, reference needed since we change cout

class Complex{
private:
	double re_; //mRe, m_re, re_ all possible
	double im_;
	
	
public:
	Complex(double re=0.0, double im=0.0);
	//copy constructor is not needed since there is one from compiler
	//destructor too!
	
	//Complex& operator=(const Complex& rhs); -> not needed either
	bool operator==(const Complex& rhs) const; //can be used for const class
	
	const Complex operator+(const Complex& rhs) const; 
	const Complex operator-(const Complex& rhs) const;
	
	double real() const;
	double imag() const;
	
	void real(double re);
	void imag(double im);

};





#endif
