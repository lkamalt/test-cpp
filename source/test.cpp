#include "test.h"

int Test::total_count = 0;
int Test::passed_count = 0;
int Test::failed_count = 0;

strvec Test::failed_test_names;

std::string Test::test_name = "";

void Test::check_cond(bool cond)
{
	total_count++;

	if (cond)
		passed_count++;
	else
	{
		failed_count++;

		if (std::find(failed_test_names.begin(), failed_test_names.end(), test_name) == failed_test_names.end())
			failed_test_names.push_back(test_name);
	}
}

void Test::are_equal(double checked_value, double standard_value, double tolerance)
{
	check_cond(is_equal(checked_value, standard_value, tolerance));
}

void Test::print_test_name(str tn)
{
	std::cout << "\n" << tn << "\n";
	test_name = tn;
}

void Test::print_results()
{
	printf("\nRESULTS:\n");
	printf("total = %d\n", total_count);
	printf("passed = %d\n", passed_count);
	printf("failed = %d\n", failed_count);

	if (!failed_test_names.empty())
	{
		std::cout << "\nFAILED TESTS NAMES:\n";
		for (str tn : failed_test_names)
			std::cout << tn << "\n";
	}
}
