#include "tools.h"

bool is_equal(double a, double b, double tolerance)
{
	return fabs(a - b) < tolerance;
}

int vect_to_double(const strvec &vect_str, dvec &vect_res)
{
	int status = 0;

	vect_res.clear();
	vect_res.resize(vect_str.size());

	for (int i = 0; i < vect_str.size(); i++)
		try 
		{
			vect_res[i] = std::stod(vect_str[i]);
		}
		catch (std::invalid_argument e)
		{
			status = -1;
			std::cout << "Can't parse: invalid arguments\n";
		}

	return status;
}
