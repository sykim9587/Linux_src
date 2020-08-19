#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "input your name: ";
	std::cin >> name;
	
	const std::string greeting = "Hello, " +name+ "!";
	
	//2nd and 4th line (*)
	const std::string spaces(greeting.size(),' ');
	const std::string second ="* "+spaces+" *";
	
	//first and fifth
	const std::string first(second.size(), '*');
	
	//const -> since those strings don't change
	std::cout<<std::endl;
	std::cout<<first<<std::endl;
	std::cout <<second <<std::endl;
	std::cout << "* "<<greeting<<" *"<<std::endl;
	std::cout <<second <<std::endl;
	std::cout<<first<<std::endl;
	
	
	return 0;
}
