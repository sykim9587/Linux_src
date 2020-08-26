#include <iostream>
#include <string>
#include <cctype>	//isspace
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> split(const string& s)
{
	vector<string> ret;
	
	string::size_type i = 0;
	while (i != s.size()) {
		while (i != s.size() && isspace(s[i]))
			++i; //spce ignoring part
		
		string::size_type j = i;
		while (j != s.size() && !isspace(s[j]))
			++j;
		if (i != j){
			ret.push_back(s.substr(i,j-i));
			i = j;
		}
			
	}
	
	return ret;
}

int main()
{
	string s;
	//getline(cin,s); -> getting one line
	while (getline(cin, s)){
		vector<string> words = split(s);
		
		for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
			cout << *iter << endl;
		
	}
	
	
	return 0;
}
