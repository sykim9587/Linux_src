#include <iostream>
#include <string>
 
int main()
{//scope main starts
 
    {   //scope main-1 start
 
        const std::string s = "a string";
        std::cout << s << std::endl;
 
        {   //scope main-1-1 starts
 
            const std::string s = "another string";
            std::cout << s << std::endl;
 
        }  //scope main-1-1 ends 
 
        ;  // the additional semi-colon
 
    }  //scope main-1 ends 
 
} 
