//Write a program that asks the user to enter two numbers and tells the user which number is larger than the other.
#include <iostream>

using std::cout; using std::endl;
using std::cin;

int main()
{
    cout << "Please enter two numbers: ";
    int a, b;
    cin >>a >> b;

    cout << "larger number is ";
    if (a >b)
        cout << a << endl;
    else
    {
        cout << b << endl;
    }
    

    return 0;
}