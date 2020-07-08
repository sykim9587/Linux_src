#include <iostream>
#include "string.h"

int main()
{
	String s1;						//default
	String s2 = "hello world"; 	//String s2("hello world");
	String s3(s2);					//copy constructor
	
	s1=s2=s3; //daisy chain (this is why we return String& for operator=)
	
	s1 = "wonderful tonight"; // this is constructor 
	
	if(s2==s3)
		std::cout<<"s2 and s3 are equal"<<std::endl;
	else
		std::cout<<"s2 and s3 are not equal"<<std::endl;
		
	s1 = s2 + "ROS";
		
	std::cout <<"s1: "<<s1.c_str()<<"\ts1 len: "<< s1.length()<<std::endl;	
	std::cout <<"s2: "<<s2.c_str()<<"\ts2 len: "<< s2.length()<<std::endl;
	std::cout <<"s3: "<<s3.c_str()<<"\ts3 len: "<< s3.length()<<std::endl;

	return 0;
}
