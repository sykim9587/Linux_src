#include <iostream>
#include <string>

//pad = spaces between the * and the 'H' from greeting
//code that doesn't have any pad
using std::string; using std::cout;
using std::endl; using std::cin;
int main()
{
	string name;
	cout << "input your name: ";
	cin >> name;
	
	const string greeting = "Hello, " +name+ "!";

	
	const int pad = 0;
	const int rows = pad*2 + 3;
	string::size_type cols = greeting.size() + pad*2 + 2; //int is also possible
	
	cout<<endl;
	for(int r=0; r != rows; ++r){
		string::size_type c = 0;	//needs to initialize
		while(c != cols){
			if (r == pad + 1 && c == pad+1){
				//greeting message
				cout <<greeting;
				c += greeting.size();
			}else{
				// '*' or ' '
				if (r == 0 || r==rows-1 || c == 0 || c == cols-1 )
					cout<<'*';
				else
					cout<<' ';
				++c;
			
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
