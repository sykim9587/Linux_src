#ifndef COMPLEX_H
#define COMPLEXH
#include <iostream>


class Complex {
friend std::istream& operator >> (std::istream& in, Complex& rhs);
friend std::ostream& operator << (std::ostream& out, const Complex& rhs);

private:
    static int numberOfComplex;
    static const int BLOCK_SIZE;
    static Complex* headOfFreeList;
	union { //biggest place (8 byte) will be shared
    	struct{
    	double re_;
    	double im_;
    	};
    	Complex *next;
	};
public:
    static int getNumberOfComplex();
    static void *operator new(size_t size); //similar to malloc
    static void operator delete(void *ptr, size_t size); //free

    Complex(double re = 0.0,    double im = 0.0);
    Complex(const Complex& rhs);
    ~Complex();

    // Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs) const;

    const Complex operator+(const Complex& rhs) const;
    const Complex operator-(const Complex& rhs) const;

    //get func
    double real() const;
    double imag() const;

    //set func
    void real(double re);
    void imag(double im);

};

#endif
