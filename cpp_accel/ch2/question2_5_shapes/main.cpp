#include "shapes.h"

//Accelerated C++ question 2_5

int main()
{
    string tryAgain = "y";
    while (tryAgain == "y"){
        Shape new_item;
        new_item.print_intro();
        new_item.menu();
        new_item.size();
        cout<<new_item.shapeType<<endl;
        cout<<new_item.shapeWidth<<endl;
        cout<<new_item.shapeHeight<<endl;



        cout << "Again? (y/n): ";
        cin >> tryAgain;
    }

    return 0;
}