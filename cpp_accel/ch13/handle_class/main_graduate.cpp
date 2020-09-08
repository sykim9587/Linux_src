#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>	//sort function

#include "student_info.h"

//using sub calss graduate. thesis mark comes before the h/w
//using virtual functions! and the data set has U or G at the front

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

int main()
{
	vector<Student_info> students;
	
	Student_info s;
	string::size_type maxLen = 0;


	while(s.read(cin)){

		maxLen = max(maxLen, s.name().size());
		students.push_back(s);
		
	}

	sort(students.begin(),students.end(),Student_info::compare); //to compare two class

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){
		cout << students[i].name() << string( maxLen + 1 - students[i].name().size(),' '); //spacing
		try{
			double final_grade = students[i].grade();	//this grade() is from graduate - virtual
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e){
			cout << e.what() << endl;
		}
	}


	return 0;
}