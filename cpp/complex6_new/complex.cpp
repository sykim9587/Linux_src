#include <sstream>
#include "complex.h"
#include <cassert>

int Complex::numberOfComplex;
const int Complex::BLOCK_SIZE = 256;

Complex *Complex::headOfFreeList = NULL; //initialized since its global

std::istream& operator >> (std::istream& in, Complex& rhs)
{
    double re = 0.0;
    double im = 0.0;
    char c = 0;

    in >> c;
    if (c == '(') {
        in >> re >> c;
        if (c == ',') in >> im >> c;
        if (c == 'i') in >> c;
        if (c != ')') in.clear(std::ios::failbit);
    } else {
        in.putback(c);
        in >> re;
    }

    if (in ) rhs = Complex(re, im);

    return in;

}
/*
std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.re << ", " << rhs.im << "i)";

    return out;
}
*/

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    std::ostringstream buf;
    buf.flags(out.flags());
    buf.precision(out.precision());

    buf << "(" << rhs.re_ << "," << rhs.im_ << "i)" << std::ends;
    out << buf.str();
    // buf.freeze(0);

    return out;
}

void *Complex::operator new(size_t size) //the pool is created! instead of making new space every time
{
	if(size != sizeof(Complex))
		return ::operator new(size); //:: means global function
	
	Complex *ptr = headOfFreeList;
	
	if(ptr ){ //the spaces are already there
		headOfFreeList = ptr->next;
	}else { //if null, if nothing is there
		Complex *pArr = reinterpret_cast<Complex*>(::operator new(Complex::BLOCK_SIZE * sizeof(Complex)));
		assert( pArr);
		
		for(int i =1; i<Complex::BLOCK_SIZE-1; ++i)
			pArr[i].next = &pArr[i+1];
		pArr[Complex::BLOCK_SIZE -1].next = NULL;
		
		headOfFreeList = &pArr[1]; 

	/*	//the reason why the for loop starts at 1
		p=headOfFreeList;
		headOfFreeList = p->next;
	*/
		ptr=pArr; //first node
	}
	
	return ptr;
	
}

void Complex::operator delete(void *ptr, size_t size)
{
	if(ptr ==0)
		return;
	if (size!=sizeof(Complex)){
		::operator delete(ptr);
		return;
	}
	
	Complex *deleteNode = reinterpret_cast<Complex *>(ptr);
	deleteNode->next = headOfFreeList;
	headOfFreeList = deleteNode;

}


int Complex::getNumberOfComplex()
{
    return Complex::numberOfComplex;
}

Complex::Complex(double re, double im)
: re_(re), im_(im)                                // constructor initialization list
{
    ++Complex::numberOfComplex;
}

Complex::Complex(const Complex& rhs)
: re_(rhs.re_), im_(rhs.im_)
{
    ++Complex::numberOfComplex;
}

Complex::~Complex()
{
    --Complex::numberOfComplex;
}

bool Complex::operator==(const Complex& rhs) const
{
    return re_ == rhs.re_ && im_ == rhs.im_;
}

const Complex Complex::operator+(const Complex& rhs) const
{
    Complex result(re_ + rhs.re_, im_ + rhs.im_);

    return result;
}

const Complex Complex::operator-(const Complex& rhs) const
{
    return Complex(re_ - rhs.re_, im_ - rhs.im_);
}

double Complex::real() const
{
    return re_;
}

double Complex::imag() const
{
    return im_;
}

void Complex::real(double re)
{
    re_ = re;
}

void Complex::imag(double im)
{
    im_ = im;
}
