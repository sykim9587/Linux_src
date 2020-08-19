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
	cout << "Enter some marks,";
	
	int count = 0;
	double sum = 0;
	
	vector<double> homework; 	//default constructor for vector - template 
	int size;
	double d;
	double median;
	int mid;
	while (cin >> d) {	//istream type 
		homework.push_back(d); //the size is changable! for vector. 
		size = homework.size();
		mid = size / 2;
		sort(homework.begin(), homework.end());
		if(size % 2) //for odd number
			median = homework[mid]; //vector has index
		else
			median = (homework[mid-1] + homework[mid]) / 2;
		cout<< "current median: "<< median <<endl;		
	} 
	
	
	return 0;
}
