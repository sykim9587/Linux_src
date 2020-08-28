//equal(b,e,d) -> b,e is the input iterator and range, d is iterator of the second container (same size)
// b,e,d: In

//find(b,e,t) -> [b,e) range, find t, returns iterator that points the first position, if not found, return e
//b,e : In

//find_if(b,e,p) ->[b,e) range, returns iterator when p is true
//b,e: In

//transform(b,e,d,f) -> [b,e) do f and then save in d, returns iterator that points one after the end of d.
//b,e: In, d: Out f:function


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector; 
using std::cout;
using std::cin;
using std::endl;
using std::equal;
using std::find;
using std::find_if;
using std::transform;
using std::back_inserter;


template <class In>
bool my_equal(In b, In e, In d)
{
    In iter2 = d;
    In iter;
    for(iter = b; iter!= e; ++iter)
    {
        if (*iter != *iter2)
            break;
        ++iter2;
    }
    return iter == e;
}

template <class In, class T>
In my_find(In b, In e, T t)
{
    In iter;
    for (iter = b; iter != e; ++iter)
    {
        if( *iter == t)
            break;
    }

    return iter;
}

bool checking_int(int a)
{
    return a>3;
}

template <class In>
In my_find_if(In b, In e, bool foo(int))
{
    In iter;
    for (iter = b; iter != e; ++iter)
    {
        if( foo(*iter))
            break;
    }

    return iter;
}

int square_int (int k)
{
    return k*k;
}

template <class In, class Out>
In my_transform(In b, In e, Out d, int foo(int))
{
    Out iter2 = d;
    for (In iter = b; iter != e; ++iter)
    {
        *iter2 =foo(*iter);
        ++iter2;
    }

    return iter2;
}

int main()
{
    
    int nums1[] = {1,2,3,4,5};
    int nums2[] = {1,2,3,4,6};
    vector<int> vec1(nums1, nums1+5);
    vector<int> vec2(nums2,nums2+5);
    cout << "------------------------------------------" << endl;

    bool re1 = my_equal(vec1.begin(), vec1.end(),vec2.begin());
    bool re2 = equal(vec1.begin(), vec1.end(),vec2.begin());
    cout << "result of my_equal: " << re1 << endl;
    cout << "result of equal: " << re2 << endl;

    cout << "------------------------------------------" << endl;
    vector<int>::const_iterator re3 = my_find(vec1.begin(), vec1.end(), 5);
    vector<int>::const_iterator re4 = find(vec1.begin(), vec1.end(),5);
    cout << "result of my_find: "<< *re3 << endl;
    cout << "result of find: " << *re4 << endl;

    cout << "------------------------------------------" << endl;
    vector<int>::const_iterator re5 = my_find_if(vec1.begin(), vec1.end(), checking_int);
    vector<int>::const_iterator re6 = find_if(vec1.begin(), vec1.end(),checking_int);
    cout << "result of my_find_if: "<< *re5 << endl;
    cout << "result of find_if: " << *re6 << endl;

    cout << "------------------------------------------" << endl;
    cout << "result of my_transform with square function: "<<endl;
    vector<int> vec3(5);
    my_transform(vec1.begin(), vec1.end(),vec3.begin(),square_int);

    for(vector<int>::const_iterator iter = vec3.begin(); iter != vec3.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "result of transform with square function: "<<endl;
    vector<int> vec4(5);
    transform(vec1.begin(), vec1.end(),vec4.begin(),square_int);

    for(vector<int>::const_iterator iter = vec4.begin(); iter != vec4.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}


