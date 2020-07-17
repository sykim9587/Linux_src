#include <iostream>
#include <cassert>
#include "rational.h"

int Rational::numberofRational;

const int Rational::BLOCK_SIZE = 256;

Rational *Rational::headOfFreeList = NULL; //initialized since its global

int Rational::getNumberofRational()
{
	return numberofRational;
}

std::istream& operator>>(std::istream& in, Rational& rhs)
{
	int num = 0;
	int den = 1;
	
	in>>num;
	if (in.peek() == '/'){
		in.ignore();
		in >> den;
	}
	
	if(in ) rhs = Rational(num,den);//checking if input is successfull
	return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& rhs) //global function
{
	out << "("<<rhs.num_<<"/ "<<rhs.den_<<")";
	return out;
}

//size_t -> unsigned data type (biggest integer) in64bit, unsigned long long (so it's better to put this 
//in for loop when it gets large)

void *Rational::operator new(size_t size) //the pool is created! instead of making new space every time
{
	if(size != sizeof(Rational)) //class size only depends on the data memeber
		return ::operator new(size); //:: means global function
	
	Rational *ptr = headOfFreeList;
	//change it to headOfFreeNode 
	if(ptr ){ //the spaces are already there
		headOfFreeList = ptr->next;
	}else { //if null, if nothing is there
		Rational *pArr = reinterpret_cast<Rational*>(::operator new(Rational::BLOCK_SIZE * sizeof(Rational)));
		assert( pArr);
		
		for(int i =1; i<Rational::BLOCK_SIZE-1; ++i)
			pArr[i].next = &pArr[i+1];
		pArr[Rational::BLOCK_SIZE -1].next = NULL;
		
		headOfFreeList = &pArr[1]; 

		ptr=pArr; //first node
	}
	
	return ptr;
	
}

void Rational::operator delete(void *ptr, size_t size)
{
	if(ptr ==0)
		return;
	if (size!=sizeof(Rational)){
		::operator delete(ptr);
		return;
	}
	
	Rational *deleteNode = reinterpret_cast<Rational *>(ptr);
	deleteNode->next = headOfFreeList;
	headOfFreeList = deleteNode;

}




static int gcd(int a, int b) //this should be in math folder
{
	if(a==0 || b==0)
		return 1;
	if(b>a){
		int tmp=a;
		a=b;
		b=tmp;
	}
	int k=-1;

	while(k!=0){
		k=a%b;
		a=b; 
		b=k;
	}
	return a;
}

void Rational::Reduce() const
{
	int tmp = gcd(num_, den_);
	num_ /=tmp;
	den_ /=tmp;
}

//constructor

Rational::Rational(const Rational& rhs)
{
	
	num_ = rhs.num_;
	den_ = rhs.den_;
	this->Reduce(); //getting reduced
	++Rational::numberofRational;
	
}


Rational::Rational(int num, int den)
: num_(num), den_(den)
{
	++Rational::numberofRational;
	assert(den!= 0);
	this->Reduce();
}


//destructor
Rational::~Rational()
{
	--Rational::numberofRational;
}

//operator overloading
/*
void Rational::operator=(const Rational& rhs)
{
	num_ = rhs.num_;
	den_ = rhs.den_;
}
*/

bool Rational::operator==(const Rational& rhs) const
{
	Rational rx=rhs;
	Rational ry(num_, den_);
	rx.Reduce();
	ry.Reduce();
	
	return (rx.num_==ry.num_ && rx.den_==ry.den_);
}

const Rational Rational::operator+(const Rational& rhs) const
{
	int num = num_*rhs.den_ + den_*rhs.num_;
	int den = den_*rhs.den_;
	Rational result(num,den);
	result.Reduce();
	return result; 
}

const Rational Rational::operator-(const Rational& rhs) const
{
 	int num = num_*rhs.den_ - den_*rhs.num_;
 	int den = den_*rhs.den_;
 	Rational result(num,den);
	result.Reduce();
	return result; 

}
const Rational Rational::operator*(const Rational& rhs) const
{
	int num_ = num_*rhs.num_;
	int den_ = den_*rhs.den_;
	Rational result(num_,den_);
	result.Reduce();
	return result;  

}

const Rational Rational::operator/(const Rational& rhs) const
{
	int num_ = num_*rhs.den_;
	int den_ = den_*rhs.num_;
	Rational result(num_,den_);
	result.Reduce();
	return result; 
}

//previous functions

int Rational::getNum() const
{
	return num_;
}

int Rational::getDen() const
{
	return den_;
}
	
