#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct Student_info{
	std::string name;
	double midterm;
	double final;
	std::vector<double> homework;
};

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& in, Student_info& s);

bool compare(const Student_info& left, const Student_info& right);

#endif
