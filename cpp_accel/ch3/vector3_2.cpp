#include <iostream>
#include <string>
#include <ios>	
#include <iomanip>
#include <vector>
#include <algorithm>	//for sort
#include <random> 	//for random


using std::cin; using std::cout;
using std::endl; using std::string;
using std::streamsize; using std::setprecision;
using std::vector; using std::sort;

int main()
{
	//from c++ 11
	std::random_device rd;
	std::mt19937 mersenne(rd());
	
	std::uniform_int_distribution<> number(1,100);
	
	vector<int> numbers;
	
	for (int i=1; i<= 100; ++i)
		numbers.push_back(number(mersenne));
		
	sort(numbers.begin(),numbers.end());		
	typedef vector<int>::size_type vec_sz;		//typedef
	for (vec_sz i=0; i < numbers.size(); ++i) 	//size_type can hold much bigger number
		cout << numbers[i] <<endl;
	
	vec_sz size = numbers.size();
	
	double Qu1 = (size %2)? numbers[size/4]: (numbers[size/4 -1]+ numbers[size/4])/2;
	double Qu2 = (size %2 ==0)? (numbers[size/2 -1] + numbers[size/2])/2 : numbers[size/2];
	double Qu3 = (size %2 ==0) ? (numbers[size * 3/4 -1] + numbers[size * 3/4])/2 : numbers[size* 3/4];
	
	cout << "1Q: " << Qu1 << endl;
	cout << "2Q: " << Qu2 << endl;
	cout << "3Q: " << Qu3 << endl;
	
	return 0;
}
