#include <iostream>
#include <string>
#include <memory> //allocator

using std::allocator;
using std::cout;
using std::endl;
using std::string;

int main ()
{
    /* origianl method using new and delete
    string *pArr = new string[5];   //not really necessary, since constructor is called later. 
    //that's why we want to have empty space.
    pArr[0] = string("AAA");
    pArr[1] = string("BBB");
    pArr[2] = string("CCC");
    pArr[3] = string("DDD");
    pArr[4] = string("FFF");

    for (int i = 0; i!=5; ++i)
        cout << pArr[i] << endl;

    delete [] pArr;

    */

    allocator<string> alloc;
    string *pArr = alloc.allocate(5);
    
    //uninitialized_fill(pArr,pArr+5,string("hello"));

    alloc.construct(pArr,"AAA");
    alloc.construct(pArr+1,"BBB");
    alloc.construct(pArr+2,"CCC");
    alloc.construct(pArr+3,"DDD");
    alloc.construct(pArr+4,"EEE");

    // string *pArr2 = alloc.allocate(5);
    //uninitialized_copy(pArr,pArr+5,pArr2);

    for (int i = 0; i!=5; ++i)
        cout << pArr[i] << endl;
    
    for (int i = 0; i!=5; ++i){
        alloc.destroy(pArr + i);
        //alloc.destroy(pArr2 + i);
    }

    alloc.deallocate(pArr, 5);
    //alloc.deallocate(pArr2, 5);
    
    return 0;

}