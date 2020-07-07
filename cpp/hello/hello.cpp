#include <iostream>

int main()
{
	std::cout<<"hello, world"<<std::endl;
	operator<<(std::cout, "Hello world").operator<<(std::endl);
	
	//std::cout<<"hello, world"; //when we type this, c++ finds global function or member function
	//operator<<(std::cout, "hello world"); //global function -> in this case, it's global function. 
	//std::cout.operator<<("hello world"); //member function -> this doesn't work
	
	operator<<(std::cout, "hello world");
	
	//std::cout<<std::endl;
	//operator<<(std::cout, std::endl);
	//std::cout.operator<<(std::endl); //this works
	
	std::cout.operator<<(std::endl); 
	
	
	return 0;
}
