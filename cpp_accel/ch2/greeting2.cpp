#include <iostream>
#include <string>

//pad = spaces between the * and the H
using std::string;
int main()
{
	std::string name;
	std::cout << "input your name: ";
	std::cin >> name;
	
	const std::string greeting = "Hello, " +name+ "!";

	
	const int pad = 3;
	const int rows = pad*2 + 3;
	string::size_type cols = greeting.size() + pad*2 + 2; //int is also possible
	
	std::cout<<std::endl;
	for(int r=0; r != rows; ++r){
		string::size_type c = 0;	//needs to initialize
		while(c != cols){
			if (r == pad + 1 && c == pad+1){
				//greeting message
				std::cout <<greeting;
				c += greeting.size();
			}else{
				// '*' or ' '
				if (r == 0 || r==rows-1 || c == 0 || c == cols-1 )
					std::cout<<'*';
				else
					std::cout<<' ';
				++c;
			
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
