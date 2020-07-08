#ifndef RATIONAL_H
#define RATIONAL_H


class Rational {
private:
	int num;
	int den; 
	//void Reduce();	//helper function: only used by member function 
public:
	Rational(int num=0, int den=1);
	Rational(const Rational& rhs);
	
	~Rational();
	
	int getNum();
	int getDen();
	
	void operator=(const Rational& rhs);
	bool operator==(const Rational& rhs);
	
	const Rational operator+(const Rational& rhs);
	const Rational operator-(const Rational& rhs);
	const Rational operator*(const Rational& rhs);
	const Rational operator/(const Rational& rhs);
	
	void Reduce();	
};

#endif
