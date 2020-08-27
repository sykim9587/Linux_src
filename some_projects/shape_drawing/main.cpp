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
        new_item.fill_style();
        new_item.dislay_info();
        new_item.draw();

        cout << "Again? (y/n): ";
        cin >> tryAgain;
    }

    return 0;
}