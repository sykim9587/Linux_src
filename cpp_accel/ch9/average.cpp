#include <vector>
#include <numeric> //accumulate
#include "average.h"

using std::vector;
using std::accumulate;

double average(const vector<double>& vec)
{
    /* //original way
    double re = 0.0;
    for (vector<double>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
        re += *iter;    
    */

   double re = accumulate(vec.begin(), vec.end(),0.0)/vec.size();

   return re;
}