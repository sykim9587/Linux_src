#include <vector>
#include <algorithm>
#include "median.h"
#include <stdexcept>

using std::vector;
using std::sort;
using std::domain_error;

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	
	if(size == 0)
		throw domain_error("median of an empty vector");
		
	sort(vec.begin(), vec.end());
	
	vec_sz mid = size / 2;
	return (size % 2) ? vec[mid] : (vec[mid-1] + vec[mid]) / 2;
	
}



