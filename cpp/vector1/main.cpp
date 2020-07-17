#include <iostream>
#include "vector.h"

int main(){

	Vector<int,10> vec1;
	Vector<int,10> vec2=vec1;
	
	std::cout<<vec2[0]<<std::endl;
	return 0;
}
