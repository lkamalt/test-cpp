#include "tools.h"

bool is_equal(double a, double b, double tolerance)
{
	return fabs(a - b) < tolerance;
}
