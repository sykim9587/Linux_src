#ifndef MEDIAN_H
#define MEDIAN_H
#include <vector>

template <typename T>
const T median(std::vector<T> vec);

#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::sort;
using std::domain_error;

template <typename T>
const T median(vector<T> vec)
{
	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = vec.size();
	
	if(size == 0)
		throw domain_error("median of an empty vector");
		
	sort(vec.begin(), vec.end());
	
	vec_sz mid = size / 2;
	return (size % 2) ? vec[mid] : (vec[mid-1] + vec[mid]) / 2;
	
}

#endif
