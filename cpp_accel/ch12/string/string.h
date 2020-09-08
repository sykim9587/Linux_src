#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include "vector.h"

class String{
friend std::istream& operator>>(std::istream& in, String& rhs);

public:
    typedef Vector<char>::size_type size_type;

    String();
    String(size_type n, char c);
    String(const char* str);

    template <typename In>
    String(In begin, In end);

    char& operator[](int index);
    const char& operator[](int index) const;

    
    String& operator+=(const String& rhs);

    size_type size() const;

private:
    Vector<char> data;
};

std::ostream& operator<<(std::ostream& out, const String& rhs);
const String operator+(const String& lhs, const String& rhs);

template <typename In>
String::String(In begin, In end)
{
    std::copy(begin, end, std::back_inserter(this->data));
}

#endif