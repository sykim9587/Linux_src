#include <iostream>
#include <string>
#include <ios>
#include <iomanip>


#ifdef _LIST_
#include <list>
#else
#include <vector>
#endif

#include <algorithm>
#include <stdexcept>
#include "student_info.h"
#include "median.h"
#include "grade.h"

//when changing to list, use _D_LIST_


using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;

#ifdef _LIST_
using std::list;
#else
using std::vector;
#endif


using std::sort;
using std::domain_error;
using std::max;


#ifdef _LIST_
typedef list<Student_info> container; 
#else
typedef vector<Student_info> container; 
#endif

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

container extract_fails(container& students)
{
	container fail;
	for (container::iterator iter = students.begin(); iter != students.end();)
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	return fail;
}

int main()
{
	container students;
	
	string::size_type maxlen = 0;
	Student_info s;
	while (read(cin, s)){
		maxlen = max(maxlen, s.name.size());
		students.push_back(s);
	}

#ifdef _LIST_
	students.sort(compare);
#else	
	sort(students.begin(), students.end(), compare);
#endif
	
	for (container::const_iterator iter = students.begin(); iter != students.end(); ++iter){
		cout << iter->name;
		cout << string(maxlen - iter->name.size() +1,' ');
		
		try{
			double final_grade = grade(*iter);
			
			streamsize prec = cout.precision();
			
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e){
			cout << e.what();
		}
	}
	
	container pass(students.begin(), students.end()); //constructor
	container fail;
	fail = extract_fails(pass);
	
	cout << "pass list: " <<endl;
	for (container::const_iterator iter =pass.begin(); iter != pass.end(); ++iter)
		cout<< iter->name <<endl;

	cout << "fail list: " <<endl;
	for (container::const_iterator iter = fail.begin(); iter != fail.end(); ++iter)
		cout<< iter->name <<endl;
	
	
	return 0;
}
