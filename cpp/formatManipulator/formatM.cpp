#include <iostream>
#include <iomanip>
using namespace std;
ostream& general(ostream& ostr){
	ostr.setf(ios_base::fmtflags(0), ios_base::floatfield);
	return ostr;
}
int main(int, char**){
	int i = 12345; double d = 3.1415;
	
	cout<<setfill('_') << showbase;
	cout<<setw(10) << dec << i;
	cout<<setw(10) <<oct << i;
	cout<<setw(10) << hex << i << endl;
	cout<<setprecision(3);
	cout<<general <<d << " ";
	cout<<scientific<<d<<" ";
	cout<<fixed<< d <<endl;
}
