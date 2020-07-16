#include "circle.h"

Circle::Circle(int x, int y, int r)
: Shape(x,y), radius_(r)
{

}

double Circle::area() const
{
	return 3.141592*radius_*radius_;
}

double Circle::circumference() const
{
	return 3.141592*(radius_+radius_);
}
