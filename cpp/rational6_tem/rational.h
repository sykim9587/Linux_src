#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational {
private:
	long num;
	long den;
	
	long gcd(long, long);
	
public:
	Rational(): num(0), den(1){}
	Rational(long n, long d = 1);
	//~Rational();
	Rational& operator=(long rhs); //rational = long value?

//access function
	long numerator(void) const {return num;}
	long denominator(void) const {return den;}
//unary operators
	Rational operator+(void) const {return *this;}
	Rational operator-(void) const {return Rational(-num,den);}
	Rational invert(void) const {return Rational(den, num); }
//binary operators (not const since it changes)
	const Rational& operator+=(const Rational& rhs); //taking const as well? or only const?
	const Rational& operator-=(const Rational& rhs); 
	const Rational& operator*=(const Rational& rhs); 
	const Rational& operator/=(const Rational& rhs); 
//binary operator for mixed mode arithmetic
	const Rational& operator+=(long rhs);
	const Rational& operator-=(long rhs);
	const Rational& operator*=(long rhs);
	const Rational& operator/=(long rhs);
//Increment, decrement
	const Rational& operator++(); //why returning const? 
	const Rational operator++(int);
	const Rational& operator--();
	const Rational operator--(int);
//converstion to double
	//operator double(void) const {return double(num)/den;} //what is the difference between double(void) ++()?

};

//Binary operator
	const Rational operator+(const Rational& l, const Rational& r);
	const Rational operator-(const Rational& l, const Rational& r);
	const Rational operator*(const Rational& l, const Rational& r);
	const Rational operator/(const Rational& l, const Rational& r);		
//Boolean operator
	bool operator==(const Rational& lhs, const Rational& rhs);
	bool operator!=(const Rational& lhs, const Rational& rhs);
	bool operator<=(const Rational& lhs, const Rational& rhs);
	bool operator>=(const Rational& lhs, const Rational& rhs);
	bool operator<(const Rational& lhs, const Rational& rhs);
	bool operator>(const Rational& lhs, const Rational& rhs);	
//output operator
	ostream& operator<< (ostream& s, const Rational& r);
//other function
	Rational rabs(const Rational& rhs); //rational absolute value

//inline functions
inline Rational& Rational::operator=(long rhs){ //why decare two times? line 17
	num = rhs; den = 1;
	return *this;
}

inline double toDouble (const Rational& r) {
	return double(r.numerator())/r.denominator();
}

//Rational to long 
inline long trunc(const Rational& r){ //getting rid of anything after point
	return r.numerator() / r.denominator(); 
}

inline long floor(const Rational& r){
	long q = r.numerator() / r.denominator();
	return (r.numerator() < 0 && r.denominator() !=1) ? --q: q; //if negative, decrease one more
}

inline long ceil(const Rational& r){
	long q = r.numerator() / r.denominator();
	return (r.numerator() >= 0 && r.denominator() !=1) ? ++q: q; //if negative, decrease one more
}

//double to Rational
//Rational toRational (double x, int iterations = 5);



#endif
