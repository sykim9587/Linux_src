#include <iostream>
#include "vector.h"
#include <iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;

//adding avail and push_back function

int main()
{
    Vector<int> v1;
    Vector<int> v2(10,0);
    // Vector<int> v2(10) is the same! (default value excist)

    int nums[] = {1,2,3,4,5};
    Vector<int> v3(nums, nums+5);   //using iterator
    Vector<int> v4 = v3;

    v1 = v3;

    for (Vector<int>::size_type i = 0; i != v1.size(); ++i){
        cout << v1[i] << endl;
    }

    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);

    /*
    for (Vector<int>::const_iterator iter = v1.begin(); iter != v1.end(); iter++)
    {
        cout << *iter << endl;
    }
    */
   copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
   cout <<endl;

    return 0;
}