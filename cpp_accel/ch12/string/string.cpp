#include "string.h"


using std::copy;
using std::back_inserter;
using std::istream;
using std::ostream;
using std::isspace;

istream& operator>>(istream& in, String& rhs)
{
    rhs.data.clear();

    char ch;
    while (in.get(ch) && isspace(ch));

    if(in){
        do rhs.data.push_back(ch);
        while (in.get(ch) && !isspace(ch));

        if (in)
            in.unget();
    }

    return in;
}

ostream& operator<<(ostream& out, const String& rhs)
{
    for (String::size_type i = 0; i != rhs.size(); ++i)
        out << rhs[i];
    
    return out;
}

const String operator+(const String& lhs, const String& rhs)
{
    String result = lhs;
    result += rhs;

    return result;
}

String::String()
{

}

String::String(size_type n, char c)
: data(n, c)
{
    
}

String::String(const char *str)
{
    copy(str, str + strlen(str), back_inserter(this->data));
}

char& String::operator[](int index)
{
    return this->data[index];
}

const char& String::operator[](int index) const
{
    return this->data[index];
}

String& String::operator+=(const String& rhs)
{
    copy(rhs.data.begin(), rhs.data.end(), back_inserter(this->data));

    return *this;
}

String::size_type String::size() const
{
    return this->data.size();
}