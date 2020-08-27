#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

//using map -> like dictionary in python 
int main()
{
    map<string, int> wordCounts;

    string s;
    while (cin >> s)
        ++wordCounts[s]; // s is the key

    for (map<string, int>::const_iterator iter = wordCounts.begin(); iter != wordCounts.end(); ++iter)
        cout<<iter->first << ":" << iter->second <<endl;
}