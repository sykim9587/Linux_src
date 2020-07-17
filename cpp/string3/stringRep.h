#ifndef STRINGREP_H
#define STRINGREP_H

class StringRep{
friend class String; //string class memeber funcs can use private memeber, but main can't use these
//string: handle , stringRep: body -> handle body structure
private:
	char *str_;
	int len_;
	int rc_;
	
	StringRep();
	StringRep(const char *s);
	StringRep(const char *s, bool);

	~StringRep();
	
	StringRep& operator=(const StringRep& rhs);
	StringRep(const StringRep& rhs);	
public:
	
};

#include <cassert>
#include <cstring>

inline StringRep::StringRep()
:str_(new char[1]), len_(1)
{
	assert(str_);
	str_[0] = '\0';
}

inline StringRep::StringRep(const char *s)
: str_(new char[strlen(s)+1]), len_(strlen(s))
{
	assert(str_);
	strcpy(str_, s);
}

inline StringRep::StringRep(const char *s, bool)
: str_(const_cast<char *>(s)), len_(strlen(s))
{

}
		
inline StringRep::~StringRep()
{
	delete [] str_;
}


#endif
