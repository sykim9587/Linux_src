#include <iostream>
#include "core.h"
#include "graduate.h"
#include "grade.h"

using std::istream;

bool compare(const Core& left, const Core& right)
{
    return left.name() < left.name();
}


Core::Core()
: midterm(0.0), final(0.0) //string and vector will get initialised
{


}

Core::Core(istream& in)
{
    this->read(in);

}

Core* Core::clone() const
{
	return new Core(*this); 	//using copy constructor

}

istream& Core::read_common(istream& in)
{
    in >> this->n >> this->midterm >> this->final;
    return in;
}

istream& Core::read_hw(istream& in)
{
	if (in ){
		this->homework.clear();
		double d;
		while (in >> d)
			this->homework.push_back(d);
		in.clear();
	}
	
	return in;
}

std::string Core::name() const
{
    return this->n;

}

double Core::grade() const
{
    return ::grade(this->midterm, this->final, this->homework);

}

std::istream& Core::read(std::istream& in)
{
   	this->read_common(in);
	this->read_hw(in);
    return in;

}