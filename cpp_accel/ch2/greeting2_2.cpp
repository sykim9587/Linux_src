#include <iostream>
#include <string>

//pad = spaces between the * and the H
//code that has different padding for side and top/bottom
using std::string; using std::cout;
using std::endl; using std::cin;
int main()
{
	string name;
	cout << "input your name: ";
	cin >> name;
	
	const string greeting = "Hello, " +name+ "!";

	
	const int spad = 1;
	const int tpad = 3;
	const int rows = tpad*2 + 3;
	string::size_type cols = greeting.size() + spad*2 + 2; //int is also possible
	
	cout<<endl;
	for(int r=0; r != rows; ++r){
		string::size_type c = 0;	//needs to initialize
		while(c != cols){
			if (r == tpad + 1 && c == spad+1){
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
