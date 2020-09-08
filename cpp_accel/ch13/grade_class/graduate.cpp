#include "graduate.h"
#include <algorithm>

using std::istream;
using std::min;

Graduate::Graduate()
:/*Core(static_cast<Core>(*this)),*/ thesis(0.0)    //slicing
{

}

Graduate::Graduate(istream& in)
{


}

istream& Graduate::read(istream& in)
{
    this->Core::read_common(in);    //this->Core:: can be skipped
    in >> thesis;
    this->read_hw(in);

    return in;


}

double Graduate::grade() const
{
    return min(this->Core::grade(), thesis);

}