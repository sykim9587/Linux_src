#ifndef STRING_H
#define STRING_H
#include <cstddef>
#include <iostream>
#include "stringRep.h"


class String{
friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
	//char *str;
	//int len;
	StringRep *ptr_;

	
	//void set_str(const char *str); //helper function(tool function) -> only used by member function
	String(const char *str, bool); //dummy arugument bool-> to use string in HEAP 
public:
	//String(); -> because of default argument
	String(const char *str = NULL);
	String(const String& rhs);
	~String();
	
	String& operator=(const String& rhs); //return String&	
	String& operator=(const char *str); //return String&	without using constructor
	
	bool operator==(const String& rhs) const;
	
	const String operator+(const String& rhs) const;
		
	const char *c_str() const; //return the string pointer
	int length() const;
	
	

};

#endif
