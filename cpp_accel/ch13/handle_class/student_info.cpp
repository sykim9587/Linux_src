#include "student_info.h"
#include "graduate.h"
#include "core.h"
#include <stdexcept>

bool Student_info::compare(const Student_info& left, const Student_info& right)
{
    return left.name() < right.name();
}

Student_info::Student_info()
:cp(0)
{

}

Student_info::Student_info(std::istream& in)
:cp(0)
{
    this->read(in);
}

//since it's created in HEAP area, we need these three to do deep copy
Student_info::Student_info(const Student_info& rhs)
:cp(0)
{
    if (rhs.cp)
        this->cp = rhs.cp->clone();
}

Student_info::~Student_info()
{
    delete this->cp; //delete the Core that was being pointed at
}

Student_info& Student_info::operator=(const Student_info& rhs)
{
    if (this != &rhs){
        delete this->cp;
        if(rhs.cp)
            this->cp = rhs.cp->clone();
        else
        {
            this->cp = 0;
        }
        
    }
    return *this;

}

std::istream& Student_info::read(std::istream& in)
{
    delete this->cp;

    char ch;
    in >> ch;
    if (ch == 'U')
        this->cp = new Core(in);
    else
    {
        this->cp = new Graduate(in);
    }
    return in;
}

std::string Student_info::name() const
{
    if(this->cp )
        return this->cp->name();
    else
        throw std::runtime_error("uninitialized student");
    
}

double Student_info::grade()const
{
    if(this->cp )
        return this->cp->grade();
    else
        throw std::runtime_error("uninitialized student");
}