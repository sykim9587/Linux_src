#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>	//sort function

#include "graduate.h"

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

bool compare_ptr(const Core* pLeft, const Core* pRight)
{
	return ::compare(*pLeft, *pRight); // sliced graduate could go in but deosn't matter since we compare names!
}

int main()
{
	vector<Core*> students;
	
	Core *pCore;
	string::size_type maxLen = 0;

	char ch;
	while(cin >> ch){
		if(ch == 'U')
			pCore = new Core;
		else
		{
			pCore = new Graduate;
		}
		pCore->read(cin);	//virtual function needed. it should be decided depending on the pointer type
		maxLen = max(maxLen, pCore->name().size());
		students.push_back(pCore);
		
	}

	sort(students.begin(),students.end(),compare_ptr); //to compare two class

	for (vector<Core*>::size_type i = 0; i != students.size(); ++i){
		cout << students[i]->name() << string( maxLen + 1 - students[i]->name().size(),' '); //spacing
		try{
		double final_grade = students[i]->grade();	//this grade() is from graduate - virtual
		streamsize prec = cout.precision();
		cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e){
			cout << e.what() << endl;
		}
	}

	for (vector<Core *>::const_iterator iter = students.begin(); iter != students.end(); ++iter)
		delete *iter;

	return 0;
}