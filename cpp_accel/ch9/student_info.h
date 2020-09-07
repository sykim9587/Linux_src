#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

class Student_info{
private:
	
	double midterm;
	double final;
	std::vector<double> homework;
	std::string n;	//memeber function and member variable can't be the same

	//private function : tool function
	std::istream& read_hw(std::istream& in);
public:
	Student_info();
	Student_info(std::istream& in);	//not used yet
	std::istream& read(std::istream& in);

	double grade_aux() const;
	double grade_average() const;
	double grade_optimistic_median() const;
	double grade() const;

	std::string name() const;	//read only object (const) can call this member function. 

	//& const, without const
	//dynamic allocation -> point: requires destructor

	//if defined here, it is inline function
	bool valid() const{
		return !this->homework.empty();
	}

};

// std::istream& read_hw(std::istream& in, std::vector<double>& hw);
// std::istream& read(std::istream& in, Student_info& s);

bool compare(const Student_info& left, const Student_info& right);

#endif
