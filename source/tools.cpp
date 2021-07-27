#include "tools.h"

bool is_equal(double a, double b, double tolerance)
{
	return fabs(a - b) < tolerance;
}

dvec vect_to_double(const strvec &vect_str)
{
	dvec vect_d(vect_str.size());

	for (int i = 0; i < vect_str.size(); i++)
		vect_d[i] = std::stod(vect_str[i]);

	return vect_d;
}
