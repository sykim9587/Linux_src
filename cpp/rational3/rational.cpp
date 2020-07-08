#include <iostream>
#include <cassert>
#include "rational.h"

static int gcd(int a, int b) //this should be in math folder
{
	if(a==0 || b==0)
		return 1;
	if(b>a){
		int tmp=a;
		a=b;
		b=tmp;
	}
	int k=-1;

	while(k!=0){
		k=a%b;
		a=b; 
		b=k;
	}
	return a;
}

void Rational::Reduce(){
	int tmp = gcd(this->num, this->den);
	this->num /=tmp;
	this->den /=tmp;
}

//constructor
Rational::Rational(const Rational& rhs)
{
	
	this->num = rhs.num;
	this->den = rhs.den;
	this->Reduce(); //getting reduced
	
}

Rational::Rational(int num, int den)
{
	assert(den != 0);
	this->num=num;
	this->den=den;
	this->Reduce();
}

//destructor
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
	Rational rx=rhs;
	Rational ry(this->num, this->den);
	rx.Reduce();
	ry.Reduce();
	
	return (rx.num==ry.num && rx.den==ry.den);
}

const Rational Rational::operator+(const Rational& rhs)
{
	int num = this->num*rhs.den + this->den*rhs.num;
	int den = this->den*rhs.den;
	Rational result(num,den);
	result.Reduce();
	return result; 
}

const Rational Rational::operator-(const Rational& rhs)
{
 	int num = this->num*rhs.den - this->den*rhs.num;
 	int den = this->den*rhs.den;
 	Rational result(num,den);
	result.Reduce();
	return result; 

}
const Rational Rational::operator*(const Rational& rhs)
{
	int num = this->num*rhs.num;
	int den = this->den*rhs.den;
	Rational result(num,den);
	result.Reduce();
	return result;  

}

const Rational Rational::operator/(const Rational& rhs)
{
	int num = this->num*rhs.den;
	int den = this->den*rhs.num;
	Rational result(num,den);
	result.Reduce();
	return result; 
}

//previous functions

int Rational::getNum(){
	return this->num;
}

int Rational::getDen(){
	return this->den;
}
	
