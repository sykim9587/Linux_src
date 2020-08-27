// Write a program to generate the product of the numbers in the range [1,10).
#include <iostream>

using std::cout; using std::endl;

int main()
{
    int mul= 1;
    for (int i = 1; i != 10; ++i)
    {
        mul *= i;
    }
    cout << "the result is " << mul << endl;
    return 0;
}