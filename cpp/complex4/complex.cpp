#include "complex.h"

#include <iostream>

int Complex::numberofComplex;

std::ostream& operator<<(std::ostream& out, const Complex& rhs) //global function
{
	//out << "("<<rhs.real()<<", "<<rhs.imag()<<"i)"; //using public function to use private members
	out << "("<<rhs.re_<<", "<<rhs.im_<<"i)";
	return out;
}

std::istream& operator>>(std::istream& in, Complex& rhs)
{
	double re = 0.0;
	double im = 0.0;
	char c = 0;
	
	in >> c;
	if (c=='(') {
		in >> re >> c;
		if (c==',') in >> im >> c;
		if (c == 'i') in >> c;
		if (c != ')') in.clear(std::ios::failbit);
	}else {
		in.putback(c);
		in >> re;
	}
	
	if( in ) rhs = Complex(re, im);
	return in;
}

int Complex::getNumberofComplex()
{
	return Complex::numberofComplex;
}


Complex::Complex(double re, double im)
: re_(re), im_(im)							//constructor initialization list
{
	++Complex::numberofComplex;
	//re_ = re;
	//im_ = im;
}

Complex::Complex(const Complex& rhs)
:re_(rhs.re_), im_(rhs.im_)
{
	
	++Complex::numberofComplex;
}

Complex::~Complex(){

	--Complex::numberofComplex;
}

bool Complex::operator==(const Complex& rhs) const
{
	return re_==rhs.re_ && im_==rhs.im_;
	//if you write im or re, "this->" is skipped 
}


const Complex Complex::operator+(const Complex& rhs) const
{
	Complex result(re_ + rhs.re_, im_ + rhs.im_);
	return result;
}


const Complex Complex::operator-(const Complex& rhs) const
{
	return Complex(re_ - rhs.re_, im_ - rhs.im_);
}
	
//get 	
double Complex::real() const
{
	return re_;
}
double Complex::imag() const
{
	return im_;

}
//set	
void Complex::real(double re)
{
	re_ = re;
}
void Complex::imag(double im)
{
	im_ = im;
}
