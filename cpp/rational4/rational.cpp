#include <iostream>
#include <cassert>
#include "rational.h"

int Rational::numberofRational;

int Rational::getNumberofRational()
{
	return numberofRational;
}

std::ostream& operator<<(std::ostream& out, const Rational& rhs) //global function
{
	out << "("<<rhs.num_<<"/ "<<rhs.den_<<")";
	return out;
}

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

void Rational::Reduce()
{
	int tmp = gcd(num_, den_);
	num_ /=tmp;
	den_ /=tmp;
}

//constructor

Rational::Rational(const Rational& rhs)
{
	
	num_ = rhs.num_;
	den_ = rhs.den_;
	this->Reduce(); //getting reduced
	++Rational::numberofRational;
	
}


Rational::Rational(int num, int den)
: num_(num), den_(den)
{
	++Rational::numberofRational;
	assert(den!= 0);
	this->Reduce();
}


//destructor
Rational::~Rational()
{
	--Rational::numberofRational;
}

//operator overloading
/*
void Rational::operator=(const Rational& rhs)
{
	num_ = rhs.num_;
	den_ = rhs.den_;
}
*/

bool Rational::operator==(const Rational& rhs) const
{
	Rational rx=rhs;
	Rational ry(num_, den_);
	rx.Reduce();
	ry.Reduce();
	
	return (rx.num_==ry.num_ && rx.den_==ry.den_);
}

const Rational Rational::operator+(const Rational& rhs) const
{
	int num = num_*rhs.den_ + den_*rhs.num_;
	int den = den_*rhs.den_;
	Rational result(num,den);
	result.Reduce();
	return result; 
}

const Rational Rational::operator-(const Rational& rhs) const
{
 	int num = num_*rhs.den_ - den_*rhs.num_;
 	int den = den_*rhs.den_;
 	Rational result(num,den);
	result.Reduce();
	return result; 

}
const Rational Rational::operator*(const Rational& rhs) const
{
	int num_ = num_*rhs.num_;
	int den_ = den_*rhs.den_;
	Rational result(num_,den_);
	result.Reduce();
	return result;  

}

const Rational Rational::operator/(const Rational& rhs) const
{
	int num_ = num_*rhs.den_;
	int den_ = den_*rhs.num_;
	Rational result(num_,den_);
	result.Reduce();
	return result; 
}

//previous functions

int Rational::getNum() const
{
	return num_;
}

int Rational::getDen() const
{
	return den_;
}
	
