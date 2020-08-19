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
	cout << "Please enter sentences: ";
	
	vector<string> words; 	//default constructor for vector - template 
	string d;
	while (cin >> d) {	//istream type 
		words.push_back(d); //the size is changable! for vector. 
	}
	
	int size = words.size();	
	sort(words.begin(), words.end());

	string min;
	string max;
	int minnum = words[0].length();
	int maxnum = words[0].length();
	for(int i = 0; i <size; i++){
		if (words[i].length() > maxnum){
			maxnum = words[i].length();
			max = words[i];
		}
		if (words[i].length() < minnum){
			minnum = words[i].length();
			min = words[i];	
		}	
	} 
	
	cout << "min word is " << min << "length is " << minnum << endl;
	cout << "max word is " << max << "length is " << maxnum << endl;	
	
	
	return 0;
}
