#include <iostream>
#include <string>
#include <cctype>	//isspace
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;

/*
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
*/

//new version of split using algorithm library
bool not_space(char ch)
{
	return !isspace(ch);
}

bool space(char ch)
{
	return isspace(ch);
}

/*
//finding a address that satisfy the function -> already declared
string::const_iterator find_if(string::const_iterator begin, string::const_iterator end, bool (*f)(char ch)) //function as an argument
{
	for (string::const_iterator it = begin; it != end; ++it )
		if(f(*it))
			break;
	return it;
}

*/


vector<string> split(const string& s)
{
	vector<string> re;

	string::const_iterator iter = s.begin();
	while(iter != s.end()){
		//version 1
		//while (iter != s.end() && isspace(*iter))
		//	++iter;

		/* //version 2
		for (string::const_iterator it = iter; it != s.end(); ++it)
			if (not_space(*it))
				break;
		*/

		//version 3
		iter = find_if(iter,s.end(),not_space); 	//function that returns bool type


		string::const_iterator iter2 = iter;
//		while(iter2 != s.end() && !isspace(*iter2))
//			++iter2;
		iter2 = find_if(iter2,s.end(),space);

		if (iter != iter2){
			re.push_back(string(iter, iter2));
			iter = iter2;
		}
	}	
	return re;
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
