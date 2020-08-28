#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::copy;
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

template <typename In>
bool my_equal(In begin, In end, In begin2)
{
    while (begin != end){
        if(*begin++ != *begin2++)
            break;
    }
    return begin == end;
}

template <typename In, typename T>
In my_find(In begin, In end, const T& value) //just in case it's the class
{
    while(begin != end)
        if(*begin++ == value)
            break;
    return begin;
}

bool greaterThanFour (int value) 
{
    return value > 4;
}

template <typename In, typename Pred>      //predict function!
In my_find_if(In begin, In end, Pred predict)
{
    while (begin != end){
        if (predict(*begin))
            break;
        ++begin;
    }
    return begin;
}

int square (int value)
{
    return value*value;
}

template <typename In, typename Out, typename Op>
Out my_transform(In begin, In end, Out des, Op func)
{
    while (begin != end){
        *des++ = func(*begin++);
    }

    return des;
}


int main()
{
    int nums[] = {1,2,3,4,5};
    vector<int> vec(nums,nums + 5);
    vector<int> vec2 = vec;

    if(my_equal(vec.begin(), vec.end(), vec2.begin()))
        cout << "vec and vec2 are equal" << endl;
    else
    {
        cout << "vec and vec2 are not equal"<<endl;
    }
    
    if (my_find(vec.begin(), vec.end(), 3) != vec.end())
        cout << "found" << endl;
    else
    {
        cout << "not found" << endl;
    }

    if (my_find_if(vec.begin(), vec.end(), greaterThanFour) != vec.end())
        cout << "element greater than 4 excist."<< endl;
    else
    {
        cout << "elements are all smaller than 4" << endl;
    }

    my_transform(vec.begin(), vec.end(), vec2.begin(), square);

/*  //original way of printing
    for (vector<int>::const_iterator iter = vec2.begin(); iter != vec2.end(); ++iter)
        cout << *iter << endl;
*/    

    copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}