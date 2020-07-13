#include <sstream>
#include "complex.h"

int Complex::numberOfComplex;


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
