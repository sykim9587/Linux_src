#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	int num_;
	int den_; 
	
public:
	Rational(int num=0, int den=1);
	
	int getNum() const;
	int getDen() const;
	
	bool operator==(const Rational& rhs) const;
	
	const Rational operator+(const Rational& rhs) const;
	const Rational operator-(const Rational& rhs) const;
	const Rational operator*(const Rational& rhs) const;
	const Rational operator/(const Rational& rhs) const;
	
	void Reduce();	
};

#endif
