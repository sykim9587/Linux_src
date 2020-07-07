#include "complex.h"
/*
Complex::Complex(){
	this->re=0.0;
	this->im=0,0;
}
*/

/*
Complex::Complex(double re){
	this->re = re;
	this->im = 0.0;
}
*/

Complex::Complex(double re, double im){
	this->re = re;
	this->im = im;
}
//Complex c4=c3 -> c3 is coppied to c and this called 'Copy constructor' AGAIN so error!
Complex::Complex(const Complex& rhs)
{
	this->re = rhs.re;
	this->im = rhs.im;
}

Complex::~Complex()
{
	//nothing
}

bool Complex::operator==(const Complex& rhs)
{
	return (this->re == rhs.re && this->im == rhs.im);
}

void Complex::operator=(const Complex&rhs)
{
	this->re = rhs.re;
	this->im = rhs.im;
}

const Complex Complex::operator+(const Complex& rhs) //since it won't change, so it's const!
{
	Complex result(this->re + rhs.re, this->im + rhs.im);
	return result; //can't pass pointer becuase the address of the local variable  will be gone 
}

const Complex Complex::operator-(const Complex& rhs) //since it won't change, so it's const!
{
	Complex result(this->re - rhs.re, this->im - rhs.im);
	return result;
}

double Complex::real()
{
	return this->re;
}

double Complex::imag()
{
	return this->im;
}

void Complex::real(double re)
{
	this->re = re;
}

void Complex::imag(double im)
{
	this->im = im;
}
