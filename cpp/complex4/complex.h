#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

//class Complex; //so we can use Complex
//std::ostream& operator<<(std::ostream& out, const Complex& rhs);//cout is a class in std::ostream, reference needed since we change cout

class Complex{
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);
friend std::istream& operator>>(std::istream& in, Complex& rhs);

private:
	double re_; //mRe, m_re, re_ all possible
	double im_;
	static int numberofComplex; //class related global variable	
	
public:
	static int getNumberofComplex(); //doesn't require object constructor. this pointer X

	Complex(double re=0.0, double im=0.0);
	//copy constructor is not needed since there is one from compiler
	//destructor too!
	Complex(const Complex& rhs);
	~Complex();
	
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
