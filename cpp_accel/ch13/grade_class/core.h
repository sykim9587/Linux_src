#ifndef CORE_H
#define CORE_H

#include <string>
#include <vector>
#include <iostream>




class Core {
public:
    Core(); // because we have members
    Core(std::istream& in);
    virtual ~Core() {}

    std::string name() const;
    virtual std::istream& read(std::istream& );
    virtual double grade() const;

protected:  //still private memmber but subclass memeber can use this. 
    double midterm;
    double final;
    std::vector<double> homework;

    std::istream& read_hw(std::istream& in);
    std::istream& read_common(std::istream& in);

private:
    std::string n;

};

bool compare(const Core& left, const Core& right);


#endif