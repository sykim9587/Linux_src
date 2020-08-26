#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
using std::list;

//Write a function named center(const vector<string>&) that returns a picture 
//in which all the lines of the original picture are padded out to their full width, 
//and the padding is as evenly divided as possible between the left and right sides of the picture. 

string::size_type width(const list<string>& lines)
{
	list<string>::const_iterator iter = lines.begin();
	string::size_type maxLen = iter->size(); // setting the first one as the maxLen for now,
	++iter; //now begin the search
	while (iter != lines.end()){
		maxLen = max(maxLen, iter->size());
		++iter;
	}
	return maxLen;
}

list<string> centre(const list<string>& lines)
{
	list<string> re;
	list<string>::size_type maxLen = width(lines);

	string border = string(maxLen + 4, '*');
	re.push_back(border);

	for(list<string>::const_iterator iter = lines.begin(); iter != lines.end(); ++iter)
		re.push_back("* "+*iter+string(maxLen - iter->size(), ' ')+ " *"); // maxlen- string becomes the space

	re.push_back(border);
	return re;
}


//horizontally adding
list<string> hcat(const list<string>& left, const list<string>& right)
{
	list<string> re;

	list<string>::const_iterator itr_i = left.begin();
	list<string>::const_iterator itr_j = right.begin();
	string::size_type width1 = width(left) + 1; //the width of the left part

	while (itr_i != left.end() || itr_j !=right.end() ) //exit when they are both finished
	{
		string s;
		
		
		if (itr_i != left.end()){
			s = *itr_i;
			++itr_i;
		}
		
		s += string(width1-s.size(), ' ');

		if (itr_j != right.end()){
			s += *itr_j;
			++itr_j;
		}

		re.push_back(s);
	
	}

	return re;
}

int main()
{
	list<string> lines;
	
	string s;
	while (getline(cin, s)){
		lines.push_back(s);
	}
	
	list<string> frameLines;
	frameLines = centre(lines);
	

	for (list<string>::const_iterator iter = frameLines.begin(); iter != frameLines.end(); ++iter)
		cout<< *iter << endl;

	return 0;
}
