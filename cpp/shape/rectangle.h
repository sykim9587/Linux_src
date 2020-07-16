#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle: public Shape{ //super class public members come to public side of sub class
private:
	int width_;
	int height_;
	
public:
	Rectangle(int x, int y, int w, int h);
	
	double area() const;
	
	int sumOfSide() const;
};

#endif
