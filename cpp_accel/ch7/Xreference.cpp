#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
using std::vector;
using std::map;
using std::find_if;

bool space(char ch)
{
    return isspace(ch);
}

bool not_space(char ch)
{
    return !isspace(ch);
}

vector<string> split(const string& s)
{
    vector<string> re;

    string::const_iterator iter = s.begin();
    while(iter != s.end()) {
        iter = find_if(iter, s.end(), not_space);

        string::const_iterator iter2 = iter;

        iter2 = find_if(iter2, s.end(), space);

        if (iter != iter2)
            re.push_back(string(iter, iter2));
            iter = iter2;
    }
    return re;
}

map<string, vector<int> > xref(istream& in, vector<string> (find_word)(const string& ) = split)
{
    map<string, vector<int> > re;

    string line;
    int lineNumber = 0;
    while (getline(in, line)) {
        ++lineNumber;
        vector<string> words = find_word(line);

        for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
            re[*iter].push_back(lineNumber);
    }

    return re;
}

int main()
{
    map<string, vector<int> > re = xref(cin);

    for (map<string, vector<int> >::const_iterator iter = re.begin(); iter != re.end(); ++iter) {
        cout << iter->first << " : ";

        for (vector<int>::const_iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2) {
            cout << *iter2 << ((iter2 + 1 != iter->second.end()) ? ", " : "");
        }

        cout << endl;
    }
    return 0;
}