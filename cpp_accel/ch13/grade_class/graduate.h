#ifndef GRADUATE_H
#define GRADUATE_H

#include <iostream>
#include "core.h"


class Graduate : public Core {     //parent comes to public
public:
    Graduate();
    Graduate(std::istream& in);
    virtual ~Graduate() {}

    virtual std::istream& read(std::istream& in);

    virtual double grade() const;   //including thesis mark
private:
    double thesis; 

};

#endif