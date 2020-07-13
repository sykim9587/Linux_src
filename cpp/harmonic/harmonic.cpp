#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out("iotest.out");
	if(!out){
		std::cerr << "can't open file" <<std::endl;
	}	
	for(int i = 1; i<= 100; ++i)
		out<<1.0/i << std::endl;
	
	double d;
	double sum = 0.0;
	std::ifstream in("iotest.out");
	
	if(!in){
		std::cerr << "can't open fil" << std::endl;
		return -1;
	}
	
	while(in >> d)
		sum += d;
	
	std::cout<<"sum: "<<sum <<std::endl;
	
	return 0;
}
