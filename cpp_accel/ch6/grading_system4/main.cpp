#include <iostream>
#include <string>
#include <vector>
#include "student_info.h"
#include "grade.h"
#include <algorithm>
#include "median.h"
#include <iterator> //back_inserter
#include "average.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::back_inserter;
using std::transform;
using std::ostream;
using std::stable_partition;


bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
	return !fgrade(s);
}

/* //original version
vector<Student_info> extract_fails(vector<Student_info>& pass)
{
	vector<Student_info> fail;

	remove_copy_if(pass.begin(),pass.end(),back_inserter(fail),pgrade); //fgrade should be false -> which means they pass
	pass.erase(remove_if(pass.begin(), pass.end(), fgrade),pass.end());

	return fail;
}
*/
//new version with stable partition
vector<Student_info> extract_fails(vector<Student_info>& pass)
{
	vector<Student_info>::iterator iter = stable_partition(pass.begin(), pass.end(), pgrade);

	vector<Student_info> fail(iter, pass.end());
	pass.erase(iter,pass.end());

	return fail;

}


int main()
{
	vector<Student_info> students;
	
	Student_info s;
	while (read(cin,s)){
		students.push_back(s);
	}

	vector<Student_info> pass = students;
	vector<Student_info> fail = extract_fails(pass);

	cout<<"pass: "<<endl;
	for(vector<Student_info>::const_iterator iter = pass.begin();iter != pass.end(); ++iter)
		cout << iter->name  <<endl; //since we can't print Student_info
	
	cout<<"fail: "<<endl;
	for(vector<Student_info>::const_iterator iter = fail.begin();iter != fail.end(); ++iter)
		cout << iter->name <<endl;
	

}