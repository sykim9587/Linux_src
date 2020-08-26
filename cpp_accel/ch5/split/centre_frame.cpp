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

	string border = string(maxLen+4, '*');
	re.push_back(border);

	for(list<string>::const_iterator iter = lines.begin(); iter != lines.end(); ++iter)
		re.push_back("* "+string((maxLen-iter->size())/2,' ')+*iter+string((maxLen-iter->size())/2,' ')+ " *"); // maxlen- string becomes the space

	re.push_back(border);
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
