#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& lines)
{
	vector<string>::const_iterator iter = lines.begin();
	string::size_type maxLen = iter->size(); // setting the first one as the maxLen for now,
	++iter; //now begin the search
	while (iter != lines.end()){
		maxLen = max(maxLen, iter->size());
		++iter;
	}
	return maxLen;
}

vector<string> frame(const vector<string>& lines)
{
	vector<string> re;
	vector<string>::size_type maxLen = width(lines);

	string border = string(maxLen + 4, '*');
	re.push_back(border);

	for(vector<string>::const_iterator iter = lines.begin(); iter != lines.end(); ++iter)
		re.push_back("* "+*iter+string(maxLen - iter->size(), ' ')+ " *"); // maxlen- string becomes the space

	re.push_back(border);
	return re;
}

//vertically concatenate
vector<string> vcat (const vector<string>& top, const vector<string>& bottom)
{
	vector<string> re;
	re = top;

//	for (vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter)
//		re.push_back(*iter);

//other way to do it - using insert member function from vector.
	re.insert(re.end(),bottom.begin(), bottom.end());

	return re;
}



//horizontally adding
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> re;

	vector<string>::size_type i = 0;
	vector<string>::size_type j = 0;
	string::size_type width1 = width(left) + 1; //the width of the left part

	while (i != left.size() || j !=right.size() ) //exit when they are both finished
	{
		string s;
		
		
		if (i != left.size()){
			s = left[i];
			++i;
		}
		
		s += string(width1-s.size(), ' ');

		if (j != right.size()){
			s += right[j];
			++j;
		}

		re.push_back(s);
	
	}

	return re;
}

int main()
{
	vector<string> lines;
	
	string s;
	while (getline(cin, s)){
		lines.push_back(s);
	}
	
	vector<string> frameLines;
	frameLines = frame(lines);
	
	// for (vector<string>::const_iterator iter = frameLines.begin(); iter != frameLines.end(); ++iter)
	// 	cout<< *iter << endl;

	vector<string> result;
	result = hcat(lines, frameLines);

	for (vector<string>::const_iterator iter = result.begin(); iter != result.end(); ++iter)
		cout<< *iter << endl;

	return 0;
}
