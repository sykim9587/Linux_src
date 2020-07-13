#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
friend std::istream& operator>>(std::istream& in, Rational& rhs);
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	int num_;
	int den_; 
	static int numberofRational; //global variable
	
public:
	static int getNumberofRational(); //global function
	Rational(int num=0, int den=1);
	Rational(const Rational& rhs);
	~Rational();
	
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
