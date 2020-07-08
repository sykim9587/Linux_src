#include "complex.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Complex& rhs) //global function
{
	out << "("<<rhs.real()<<", "<<rhs.imag()<<"i)"; //using public function to use private members
	return out;
}

Complex::Complex(double re, double im)
: re_(re), im_(im)							//constructor initialization list
{
	//re_ = re;
	//im_ = im;
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
