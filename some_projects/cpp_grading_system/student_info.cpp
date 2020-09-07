#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "student_info.h"
#include "grade.h"
#include "median.h"
#include "average.h"

using std::istream;
using std::vector;
using std::string;
using std::remove_copy;
using std::domain_error;



bool compare(const Student_info& left, const Student_info& right)
{
	return left.name() < right.name();	//since it's global, it can't use the private variable
}

Student_info::Student_info()
: midterm(0.0), final(0.0)	//name("Kim") if we have default value
{
	//name (sting class default constructor will be called), mideterm, final, homework (vector class default constructor)
}

Student_info::Student_info(istream& in)
{
	this->read(in);
}

istream& Student_info::read_hw(istream& in)
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

istream& Student_info::read(istream& in)
{
	in >> this->n >> this->midterm >> this->final;
	//::read_hw(in, this->homework);	//global function
	this->read_hw(in);
	return in;
}

double Student_info::grade() const
{
	return ::grade(this->midterm, this->final, ::median(this->homework) ); // use global grade function
}

string Student_info::name() const
{
	return this->n;
}


double Student_info::grade_aux() const //since grade is overloaded, it doesn't know which one to do. so we made grade_aux
{
	try {
		return this->grade();
	}
	catch(domain_error){
		return ::grade(this->midterm, this->final, 0); //no homework
	}



}

double Student_info::grade_average() const
{
	return ::grade(this->midterm, this->final, ::average(this->homework));
}

double Student_info::grade_optimistic_median() const
{
	vector<double> nonzero;
	remove_copy(this->homework.begin(), this->homework.end(), back_inserter(nonzero),0); //copy the scores that are not zero

	if(nonzero.empty())
		return ::grade(this->midterm, this->final, 0);
	else
	{
		return ::grade(this->midterm, this->final, ::median(nonzero));
	}
	
}