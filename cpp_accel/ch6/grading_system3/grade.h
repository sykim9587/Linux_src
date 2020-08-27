#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "student_info.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);
double grade_aux(const Student_info& s);
double grade_average(const Student_info& s);
double grade_optimistic_median(const Student_info& s);
#endif
