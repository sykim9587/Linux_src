#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::equal;
/*  //there is a function already made in algorithm! 
template <typename ITERATOR, typename ITERATOR2>
bool my_equal(ITERATOR begin, ITERATOR end, ITERATOR2 begin2)
{
    ITERATOR2 iter2 = begin2; // the last letter
    ITERATOR iter;
    for (iter = begin; iter != end; ++iter, ++iter2)
    {
        if (*iter != *iter2)
            break;
        
    }

    return iter == end;
}
*/



int main()
{
    /* // working of reverse_iterator, rbegin, rend
    vector<string> words;
    words.push_back("aaa");
    words.push_back("bbb");
    words.push_back("ccc");
    words.push_back("ddd");

    for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++ iter)
        cout << *iter << endl;
    for (vector<string>::const_reverse_iterator iter = words.rbegin(); iter != words.rend(); ++ iter)
        cout << *iter << endl;

    */
    string s = "madam"; //eye, level

    if(equal(s.begin(), s.end(), s.rbegin()))   //template type is decided after looking at the argument
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    

    return 0;
}