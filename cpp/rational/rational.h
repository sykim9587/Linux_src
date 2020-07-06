#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int num;
	int den; //denominator
public:
	Rational();
	Rational(int num);
	Rational(int num, int den);
	
	~Rational();
	
	int getNum();
	int getDen();
	
	void setNum(int num);
	void setDen(int den);

};

#endif
