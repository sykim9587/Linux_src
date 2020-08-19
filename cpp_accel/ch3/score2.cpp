#include <iostream>
#include <string>
#include <ios>	
#include <iomanip>
#include <vector>
#include <algorithm>	//for sort


using std::cin; using std::cout;
using std::endl; using std::string;
using std::streamsize; using std::setprecision;
using std::vector; using std::sort;

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
	
	vector<double> homework; 	//default constructor for vector - template 
	double d;
	while (cin >> d) {	//istream type 
		homework.push_back(d); //the size is changable! for vector. 
	}
	
	int size = homework.size();
	
	if (size ==0) { 	//nothing is in this vector
		cout << "no homework grade, please try again" << endl;
		return -1;
	}
	
	sort(homework.begin(), homework.end());
	
	//median - the value in the middle
	double median;
	int mid = size / 2;
	if(size % 2) //for odd number
		median = homework[mid]; //vector has index
	else
		median = (homework[mid-1] + homework[mid]) / 2;
		
	
	streamsize prec = cout.precision(); 
	
	cout << "Your final grade is " << setprecision(5) <<
	 0.2* midterm + 0.4* final + 0.4 * median 
	<< setprecision(prec) << endl; 		//putting the precision back to original. 
	
	
	return 0;
}
