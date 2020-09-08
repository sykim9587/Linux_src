#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>	//sort function

#include "core.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
using std::sort;
using std::streamsize;
using std::setprecision;
using std::domain_error;

//making struct to class, making member functions respectively. 

int main()
{
	vector<Core> students;
	
	Core s;
	string::size_type maxLen = 0;

	while(s.read(cin)){
		maxLen = max(maxLen, s.name().size());
		students.push_back(s);
	}

	sort(students.begin(),students.end(),compare); //to compare two class

	for (vector<Core>::size_type i = 0; i != students.size(); ++i){
		cout << students[i].name() << string( maxLen + 1 - students[i].name().size(),' '); //spacing
		try{
		double final_grade = students[i].grade();	//grade(students[i])
		streamsize prec = cout.precision();
		cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e){
			cout << e.what() << endl;
		}
	}

	return 0;
}