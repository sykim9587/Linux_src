#ifndef GRADUATE_H
#define GRADUATE_H

#include <iostream>
#include "core.h"
#include "student_info.h"


class Graduate : public Core {     //parent comes to public
friend class Student_info; 
public:
    Graduate();
    Graduate(std::istream& in);
    virtual ~Graduate() {}

    virtual std::istream& read(std::istream& in);

    virtual double grade() const;   //including thesis mark
protected:
    virtual Graduate* clone() const;
private:
    double thesis; 

};

#endif