#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include "core.h"
#include <istream>
#include <string>



class Student_info {
public:
    //global but related to this class
    static bool compare(const Student_info& left, const Student_info& right);

    Student_info();
    Student_info(std::istream& in);

    //since it's crated in HEAP area, we need these three to do deep copy
    Student_info(const Student_info& rhs);
    ~Student_info();
    Student_info& operator=(const Student_info& rhs);

    std::istream& read(std::istream& in);
    std::string name() const;
    double grade()const;

private:
    Core* cp;

};


#endif