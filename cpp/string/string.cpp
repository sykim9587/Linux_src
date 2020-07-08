#include "string.h"
#include <cstring>
#include <cstddef>
#include <cassert>

String::String(const char *str, bool )  // when there is string in heap section already, use this. 
{
	this->str = str;
	this->len = strlen(str);
}

void String::set_str(const char* str)
{
	if(str){ //if not NULL
		this->len = strlen(str); 
		this->str = new char[this->len+1];
		assert(this->str);
		strcpy(this->str, str);
	}
	else{
		this->len = 0;
		this->str = new char[1]; //to use delete
		//this->str = new char; will still get one space but not when "delete [] p" will be used later!
		//"delete p"; will be used. 
		assert(this->str);
		this->str[0]='\0';
	}

}

/*
String::String()
{
	this->set_str(NULL);
}
*/


String::String(const char *str) 
{
	this->set_str(str);
}


String::String(const String& rhs)
{
	this->set_str(rhs.str);
}

String::~String()
{
	delete [] this->str; //array delete 
	//delete this->str; if it's not array
}

//member functions

String& String::operator=(const String& rhs) //deep copy needed
{
	if(this !=&rhs){ //self assignment (deleting the array will create error), putting address of the rhs
	delete [] this->str;
	this->set_str(rhs.str);
	}
	
	return *this; //value of the 'this' pointer = Class

}

String& String::operator=(const char *str) //faster when string is given 
{
	if(this->str != str){
		delete [] this->str;
		this->set_str(str);
	}
	
	return *this;
}


	
bool String::operator==(const String& rhs)
{
	return strcmp(this->str,rhs.str)==0;
}
/* //original one
const String String::operator+(const String& rhs)
{
	char *buf = new char[this->len + rhs.len +1];
	strcpy(buf, this->str);
	strcat(buf, rhs.str); //adding
	
	String result(buf);
	delete [] buf;
	return result;
}
*/


const String String::operator+(const String& rhs)
{
	char *buf = new char[this->len + rhs.len +1];
	strcpy(buf, this->str);
	strcat(buf, rhs.str); //adding
	
	String result(buf, true); //special constructor that use the string already in heap section
	//delete [] buf;
	return result;
}

const char *String::c_str()
{
	return this->str;
}

int String::length()
{
	return this->len;
}
