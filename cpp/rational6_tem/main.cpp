#include <iostream>
#include "rational.h"

//final complete class for Rational from textbook

int main()
{
	
	cout<<endl<<"####Testing member Functions####"<<endl;
	Rational r1(8,4);
	Rational r2(2,1);
	Rational r3; 			//with default
	Rational r4 = 3;		//operator=
	
	cout<<"r1: "<<r1<<endl;
	cout<<"r1 denominator: "<<r1.denominator()<<" r1 numerator: "<<r1.numerator()<<endl;
	cout<<"inverted r1: "<<r1.invert()<<endl; //using invert function
	cout<<"r2: "<<r2<<endl;
	cout<<"-r2: "<<-r2<<endl; //using operator- (inside the class)
	cout<<"r3: "<<r3<<endl;
	cout<<"r4: "<<r4<<endl;	
	
	r4+=r1;
	cout<<"after r4+=r1, r4 is "<< r4 <<endl;
	r4*=r1;
	cout<<"after r4*=r1, r4 is "<< r4 <<endl;
	r4/=10;
	cout<<"after r4/=10, r4 is "<< r4<<endl;	//using operator/= with long rhs variable
	cout<<"++r4 is "<<++r4<<endl;
	cout<<"r4++ is "<<r4++<<endl;
	cout<<"current r4 is "<<r4<<endl;
	
	
	cout<<endl<<"####Testing inline Functions####"<<endl;
	Rational r5(-3,7);
	cout<<"r5 is "<<r5<<endl;
	cout<<"rabs(r5) is "<<rabs(r5)<<endl;
	cout<<"toDouble(r5) is "<<toDouble(r5)<<endl;
	cout<<"trunc(r5) is "<<trunc(r5)<<endl;	
	cout<<"floor(r5) is "<<floor(r5)<<endl;
	cout<<"ceil(r5) is "<<ceil(r5)<<endl;

	cout<<endl<<"####Testing global Binary operators####"<<endl;	
	Rational r6(2,3);
	Rational r7(7,9);
	cout<<"r6 = "<<r6<<endl;
	cout<<"r7 = "<<r7<<endl;	
	Rational r8 = r6+r7;
	cout<<"r8=r6+r7, so r8 is "<<r8<<endl;
	r8 = r6-r7;
	cout<<"r8=r6-r7, so r8 is "<<r8<<endl;	
	r8 = r6*r7;
	cout<<"r8=r6*r7, so r8 is "<<r8<<endl;	
	r8 = r6/r7;
	cout<<"r8=r6/r7, so r8 is "<<r8<<endl;	
		
	if(r1==r2) cout<<"r1 and r2 are equal"<<endl;
	else cout<<"they are not equal"<<endl;
	
	if(r6!=r7) cout<<"r6 and r7 are not equal"<<endl;
	else cout<<"r6 and r7 are equal"<<endl;
	
	if(r6>r7) cout<<"r6 is bigger than r7"<<endl;
	else cout<<"r6 is smaller than r7"<<endl;
	
	return 0;
}
