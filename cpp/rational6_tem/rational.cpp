#include "rational.h"
#include <stdlib.h>

long Rational::gcd(long u, long v){
	long a = labs(u) , b=labs(v);
	long tmp;
	
	if (b>a){
		tmp = a; a=b; b= tmp; //keeping a is bigger
	}
	for(;;){
		if (b==0L)
			return a;
		else if (b==1L)
			return b;
		else {
			tmp = b; b = a%b; a=tmp;
		}
	}
}

Rational::Rational (long n, long d) {
	if (d == 0L) {
		cerr<< "Division by Zero" <<endl;
		exit(1);
	}
	//sign in numerator
	if(d < 0L) {n = -n; d = -d;}
	
	if(n==0L) {
		num=0L; den = 1L;
	}
	else{
		long g = gcd(n,d);
		num = n/g; den = d/g;
	}
}

//+ operator
const Rational& Rational::operator+=(const Rational& rhs){
	long g1=gcd(den,rhs.den);
	if (g1==1L){
		num = num*rhs.den + den*rhs.num;
		den = den*rhs.den;
	} else{
		long t = num*(rhs.den/g1) + (den/g1)*rhs.num;
		long g2 = gcd(t,g1);
		num = t/g2;
		den = (den/g1) * (rhs.den/g2);
	}
	return *this;
}

const Rational& Rational::operator+=(long rhs){
	num=num+den*rhs;
	return *this;
}

const Rational operator+(const Rational& l, const Rational& r){
	return Rational(l) += r;
}

//- operator
const Rational& Rational::operator-=(const Rational& rhs){
	long g1=gcd(den,rhs.den);
	if (g1==1L){
		num = num*rhs.den - den*rhs.num;
		den = den*rhs.den;
	} else{
		long t = num*(rhs.den/g1) - (den/g1)*rhs.num;
		long g2 = gcd(t,g1);
		num = t/g2;
		den = (den/g1) * (rhs.den/g2);
	}
	return *this;
}

const Rational& Rational::operator-=(long rhs){
	num=num-den*rhs;
	return *this;
}

const Rational operator-(const Rational& l, const Rational& r){
	return Rational(l) -= r;
}

//* operator

const Rational& Rational::operator*=(const Rational& rhs){
	long g1= gcd(num, rhs.den);
	long g2= gcd(den, rhs.num);
	num = (num/g1) * (rhs.num/g2);
	den = (den/g2) * (rhs.den/g1);
	return *this;
}

const Rational& Rational::operator*=(long rhs){
	long g = gcd(den, rhs);
	num *= rhs/g;
	den /= g;
	return *this;
}

const Rational operator*(const Rational& l, const Rational& r){
	return Rational(l) *= r;
}

// / operator
	
const Rational& Rational::operator/=(const Rational& rhs){
	if (rhs==0) {
		cerr<< "Division by Zero" <<endl;
		exit(1);
	}
	long g1= gcd(num, rhs.num);
	long g2= gcd(den, rhs.den);
	num = (num/g1) * (rhs.den/g2);
	den = (den/g2) * (rhs.num/g1);
	if(den < 0L) {num = -num; den = -den; }
	return *this;
}

const Rational& Rational::operator/=(long rhs){
	if (rhs == 0L) {
		cerr<< "Division by Zero" <<endl;
		exit(1);
	}
	long g = gcd(num, rhs);
	num /=g;
	den *= rhs/g;
	if(den < 0L) {num = -num; den = -den; }	
	return *this;
}

const Rational operator/(const Rational& l, const Rational& r){
	return Rational(l) /= r;
}

//prefix
const Rational& Rational::operator++(){
	return (*this += 1);
}

const Rational& Rational::operator--(){
	return (*this -= 1);
}
//postfix -> evaulate first and change the value 
const Rational Rational::operator++(int){ 			
//int is default 0, it tells the compiler if this is postfix
	Rational oldVal = *this;
	++(*this);
	return oldVal;
}

const Rational Rational::operator--(int){
	Rational oldVal = *this;
	--(*this);
	return oldVal;
}

//now global operators- to get converstion on both arguments

bool operator ==(const Rational& lhs, const Rational& rhs) {
	return (lhs.numerator() == rhs.numerator() && lhs.denominator() == rhs.denominator());
}

bool operator !=(const Rational& lhs, const Rational& rhs) {
	return (lhs.numerator() != rhs.numerator() || lhs.denominator() != rhs.denominator());
}

bool operator <(const Rational& lhs, const Rational& rhs) {
	return (toDouble(lhs)<toDouble(rhs));
}

bool operator >(const Rational& lhs, const Rational& rhs) {
	return (toDouble(lhs)>toDouble(rhs));
}

bool operator <=(const Rational& lhs, const Rational& rhs) {
	return ((lhs < rhs)|| (lhs == rhs));
}

bool operator >=(const Rational& lhs, const Rational& rhs) {
	return ((lhs > rhs)|| (lhs == rhs));
}

//more functions
Rational rabs(const Rational& r){
	if (r.numerator() < 0) return -r; else return r;
}

ostream& operator<< (ostream& s, const Rational& r) {
	if (r.denominator() == 1L)
		s<<r.numerator();
	else{
		s<<r.numerator();
		s<<"/";
		s<<r.denominator();
	}
	
	return s;
}
