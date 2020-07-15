#include <iostream>
#include <cmath>
#include "rational.h"

//final complete class for Rational from textbook

Rational harmonic(int n){
	Rational r = 1;
	for (int i=2; i<=n; ++i) r+= Rational(1,i);
	return r;
}

Rational binomial (int n, int k){
	if (n<0) {cerr << "1st out of range" << endl; exit(1);}
	if (k<0 || k>n){
		cerr << "2nd out of range" << endl; exit(1); 
	}
	if (k > n-k) k = n-k;
	if (k ==0) return 1;
	return Rational(n-k+1, k) * binomial(n,k-1);
}

Rational bernoulli(int n){
	if(n<0) {cerr << "index out of range" << endl; exit(1); }
	else if (n==0) return 1;
	else if (n==1) return Rational(-1,2);
	if(n%2) return 0;
	Rational r=0;
	for (int k=0; k<n; ++k){
		r -= binomial(n+1, k) * bernoulli(k);
	}
	r /= n+1;
	return r;
}
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

	cout<<endl<<"####Testing torational function####"<<endl;		
	cout<<"toRational(0.75) is "<<toRational(0.75,5)<<endl;
	
	cout<<endl<<"####Testing Harmonic Number####"<<endl;		
	cout<<"n\tEuler Approx. \tHarmonic(n)"<<endl;
	cout<<"========================================" << endl;
	for(int n=1; n<25; ++n){
		Rational r=harmonic(n);
		double g = toDouble(r) - log(n);
		g -= (1.0/(2*n)) * (1.0-(1.0/(6*n)));
		cout<<n<<'\t'<<g<<'\t'<<r<<endl;
	}
	
	cout<<endl<<"####Testing Bernoulli function####"<<endl;		
	cout<<endl<<"n\tBernoulli(n)"<<endl;
	cout<<"======================================="<<endl;
	Rational b;
	for (int n=0; n<23; ++n){
		if((b=bernoulli(n)) != 0) cout<<n<<'\t'<<b<<endl;
	}
	
	return 0;
}
