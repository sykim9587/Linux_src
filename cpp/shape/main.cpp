#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include <typeinfo>

void printAreaOfShapeArray(Shape **ptrArray, int size) //pointer Array => double pointer!
{
	for (int i=0; i<size; ++i)
	{
		if(typeid(*ptrArray[i])==typeid(Rectangle)){
			std::cout<< "rectangle";
		}
		else if (typeid(*ptrArray[i])==typeid(Circle)){
			std::cout<<"Circle";
		}
		else 
			;
		std::cout <<" area: "<<ptrArray[i]->area() <<std::endl;
	}
}
void printArea(const Shape *ps)
{
	if (typeid(*ps) == typeid(Rectangle)) 	//runtime type identification [RTTI]
		std::cout<< "rectangle" ;
	else if (typeid(*ps) == typeid(Circle))
		std::cout<< "circle";
	else
		; //for later extension
	std::cout << "area: "<< ps->area()<<std::endl;
	//polymorphism & dynamic binding
}

int main()
{
	//Shape s(100,200) X 
	Shape *ps = new Rectangle(100,200,10,50);
	delete ps;
	Circle c(200,200,10);
	Shape &r = c;
	
	Shape *shapes[5];
	shapes[0] = new Rectangle(100,200,10,50);
	shapes[1] = new Circle(200, 100, 5);
	shapes[2] = new Rectangle(50,50,100,10);
	shapes[3] = new Rectangle(100,50,5,5);
	shapes[4] = new Circle(200,200,10);
	
	for (int i=0; i<5; ++i){
		if(typeid(*shapes[i]) == typeid(Rectangle)){ //very common method in JAVA
			Rectangle * pr = (Rectangle*)shapes[i]; //changing the pointer type
			std::cout << "sumOfSide: "<< pr->sumOfSide() << std::endl;
		} else if(typeid(*shapes[i]) == typeid(Circle)){
			Circle* pc = (Circle*)shapes[i]; //changing the pointer type
			std::cout << "circumference: "<< pc->circumference() << std::endl;			
		}else{
		
		}
	}
	
	for(int i=0; i<5; ++i)
		printArea(shapes[i]); //pointer address is delievered
		
	printAreaOfShapeArray(shapes,5);
		
	for(int i=0; i<5; ++i)
		delete shapes[i];
	return 0;
}
