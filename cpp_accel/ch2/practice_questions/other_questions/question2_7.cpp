#include <iostream>

using std::cout; using std::endl;

// Write a program that count down from 10 to -5

int main()
{
    for(int i = 10; i >= -5; --i){
        cout << i << endl;
    }
    return 0;
}