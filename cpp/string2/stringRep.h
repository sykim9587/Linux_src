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

#endif
