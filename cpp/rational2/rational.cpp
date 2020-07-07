#include <iostream>
#include <cassert>
#include "rational.h"

Rational::Rational(const Rational& rhs)
{
	this->num = rhs.num;
	this->den = rhs.den;
}

Rational::Rational(int num, int den)
{
	assert(den != 0);
	this->num=num;
	this->den=den;
}

Rational::~Rational()
{
	//nothing
}

//operator overloading
void Rational::operator=(const Rational& rhs)
{
	this->num = rhs.num;
	this->den = rhs.den;
}

bool Rational::operator==(const Rational& rhs)
{
	return (this->num==rhs.num && this->den==rhs.den);
}

const Rational Rational::operator+(const Rational& rhs)
{
	Rational result(this->num*rhs.den + this->den*rhs.num, this->den*rhs.den);
	return result; 
	//return Rational(num,den);
}

const Rational Rational::operator-(const Rational& rhs)
{
 	Rational result(this->num*rhs.den - this->den*rhs.num, this->den*rhs.den);
	return result; 

}
const Rational Rational::operator*(const Rational& rhs)
{
	Rational result(this->num*rhs.num, this->den*rhs.den);
	return result; 

}

const Rational Rational::operator/(const Rational& rhs)
{
	Rational result(this->num*rhs.den, this->den*rhs.num);
	return result; 
}

//previous functions

int Rational::getNum(){
	return this->num;
}

int Rational::getDen(){
	return this->den;
}
	
void Rational::setNum(int num){
	this->num = num;
}

void Rational::setDen(int den){
	this->den = den;
}
