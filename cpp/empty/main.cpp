#include "empty.h"

int main()
{

	//compiler has default constructor/destructor 
	Empty e1;
	Empty e2(e1);
	
	e1=e2;
	
	Empty *p;
	p= &e1; //can be done
	
	const Empty e3; //6th member function -> const member function 
	&e3;
	
	return 0;
}
