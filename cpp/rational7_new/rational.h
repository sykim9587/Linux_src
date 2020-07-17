#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
friend std::istream& operator>>(std::istream& in, Rational& rhs);
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	union { //biggest place (8 byte) will be shared
    	struct{
    		mutable int num_;
			mutable int den_; 
    	};
    	Rational *next;
	};

	static int numberofRational; //global variable
	static const int BLOCK_SIZE;
	static Rational* headOfFreeList;
	
public:
	static void *operator new(size_t size); //similar to malloc
	static void operator delete(void *ptr, size_t size); //free
	
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
	
	void Reduce() const;	
};

#endif
