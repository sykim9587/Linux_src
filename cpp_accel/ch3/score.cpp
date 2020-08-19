#include <iostream>
#include <string>
#include <ios>	
#include <iomanip>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::streamsize; using std::setprecision;

int main()
{
	cout << "Please enter you first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << endl;
	
	cout << "input your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	
	cout << "Enter all your homework grades,";
	
	int count = 0;
	double sum = 0;
	
	double d;
	while (cin >> d) {	//istream type 
		++count;
		sum += d;
	}
	
	streamsize prec = cout.precision(); 
	
	cout << "Your final grade is " << setprecision(5) <<
	 0.2* midterm + 0.4* final + 0.4 * sum/count 
	<< setprecision(prec) << endl; 		//putting the precision back to original. 
	
	
	return 0;
}
