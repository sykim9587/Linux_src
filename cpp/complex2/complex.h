#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
	double re;	//real
	double im;	//imaginary
public:
								
	Complex(double re=0.0, double im=0.0);	
	//Complex(Complex c);					//struct should use pointer to decrease overhead -> infinite copy constructor 
	Complex(const Complex& rhs);			//right hand side => passing reference 
	//Complex(const Complex *pc); 		//Complex c4(&c3) passing pointer of struct, not recommended, not in good shape
	~Complex();							
	
	
	//void operator=(Complex c); 			//copy constructor creates overhead
	//void operator=(const Complex *pc); 	//c1 = &c3; putting address to c1? works but not recommended
	void operator=(const Complex& rhs);	// the best!
	
	bool operator==(const Complex& rhs); //true, false
	
	const Complex operator+(const Complex& rhs);
	const Complex operator-(const Complex& rhs);	
	//get value
	double real();
	double imag();
	
	//set value -> setReal setImag
	void real(double re);
	void imag(double im); 
};

#endif

//Complex r2(3.0); -> goes into the first argument
