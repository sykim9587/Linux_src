#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using std::cin; using std::endl;
using std::cout; using std::string;

class Shape{
private:

public:
    void print_intro();
    void menu();
    void size();
    void fill_style();
    void dislay_info();
    void draw();
    int choice;
    int shapeType = 0;
    int shapeHeight;
    int shapeWidth;  
    int fillstyle; 
};






#endif