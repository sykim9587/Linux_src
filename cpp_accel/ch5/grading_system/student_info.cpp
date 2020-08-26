#include <iostream>
#include <vector>
#include "student_info.h"

using std::istream;
using std::vector;

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in ){
		hw.clear();
		double d;
		while (in >> d)
			hw.push_back(d);
		in.clear();
	}
	
	return in;
}

istream& read(istream& in, Student_info& s)
{
	in >> s.name >> s.midterm >> s.final;
	read_hw(in, s.homework);
	return in;
}

bool compare(const Student_info& left, const Student_info& right)
{
	return left.name < right.name;
}

