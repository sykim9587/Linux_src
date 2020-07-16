#ifndef SHAPE_H
#define SHAPE_H

class Shape{ //abstract base class (ABC)
protected:
	int x_;
	int y_;

public:
	Shape(int x, int y); //doesn't needed since no object can be made
	virtual ~Shape() {} 
	//making it inline function 
	//don't forget to make it virtual
	
	void move(int offsetX, int offsetY);
	virtual double area() const = 0; //since it doesn't change & pure virtual function
	//telling subclass to write definition
};

#endif
