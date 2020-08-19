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
	
	if (size ==0) { 	//nothing is in this vector
		cout << "no homework grade, please try again" << endl;
		return -1;
	}
	
	sort(words.begin(), words.end());
	int count = 1;
	
	
	for(int i = 0; i <size; i++){
		//cout << words[i] << endl;
		
		if (i ==0 || (words[i] != words[i-1])){
			if (i != 0){
				cout << count << endl;
				count = 1;
			}

			cout<<words[i]<< ": ";
		}
		else {
			count++;
			if (i == size-1) 
				cout << count << endl;
		}
		
	} 
	
	
	return 0;
}
