#include "stringRep.h"
#include <cassert>
#include <cstring>

StringRep::StringRep()
:str_(new char[1]), len_(1)
{
	assert(str_);
	str_[0] = '\0';
}

StringRep::StringRep(const char *s)
: str_(new char[strlen(s)+1]), len_(strlen(s))
{
	assert(str_);
	strcpy(str_, s);
}

StringRep::StringRep(const char *s, bool)
: str_((char *)s), len_(strlen(s))
{

}
	
	
StringRep::~StringRep()
{
	delete [] str_;
}

