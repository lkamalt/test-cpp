#include "funcs_test.h"

#include "funcs.h"

dvec FuncsTest::vect0 = { };
dvec FuncsTest::vect1 = { 1, 2, 3, 5, 6, 7 };
dvec FuncsTest::vect2 = { 1, 2, 3, 5, 6, 7, 8, 10 };
dvec FuncsTest::vect3 = { 3, 7, 1, 5, 9 };
dvec FuncsTest::vect4 = { 1, 5, 8, 4, 3, 9 };
dvec FuncsTest::vect5 = { 2 };
dvec FuncsTest::vect6 = { 1, 2 };

std::array<double, 6> FuncsTest::arr1 = { 1, 5, 8, 4, 3, 9 };
std::array<int, 5> FuncsTest::arr2 = { 3, 7, 1, 5, 9 };
std::list<double> FuncsTest::l1 = { 1, 2, 3, 5, 6, 7, 8, 10 };
std::list<int> FuncsTest::l2 = { 1, 2, 3, 5, 6, 7, 8, 10 };

void FuncsTest::test_mean_v1()
{
	print_test_name(__FUNCTION__);

	double mean;
	int status = Funcs::get_mean(vect1, mean);
	are_equal(mean, 4.0);
}

void FuncsTest::test_mean_v2()
{
	print_test_name(__FUNCTION__);

	double mean;
	int status = Funcs::get_mean(vect2, mean);
	are_equal(mean, 5.25);
}

void FuncsTest::test_mean_arr1()
{
	print_test_name(__FUNCTION__);

	double mean;
	int status = Funcs::get_mean(arr1, mean);
	are_equal(mean, 5.0);
}

void FuncsTest::test_mean_arr2()
{
	print_test_name(__FUNCTION__);

	double mean;
	int status = Funcs::get_mean(arr2, mean);
	are_equal(mean, 5.0);
}

void FuncsTest::test_mean_l1()
{
	print_test_name(__FUNCTION__);

	double mean;
	int status = Funcs::get_mean(l1, mean);
	are_equal(mean, 5.25);
}

void FuncsTest::test_mean_l2()
{
	print_test_name(__FUNCTION__);

	double mean;
	int status = Funcs::get_mean(l2, mean);
	are_equal(mean, 5.25);
}

void FuncsTest::test_std_v1()
{
	print_test_name(__FUNCTION__);

	double std;
	int status = Funcs::get_std(vect1, std);
	are_equal(std, 2.16024689947);
}

void FuncsTest::test_std_v2()
{
	print_test_name(__FUNCTION__);

	double std;
	int status = Funcs::get_std(vect2, std);
	are_equal(std, 2.90473750966);
}

void FuncsTest::test_std_arr1()
{
	print_test_name(__FUNCTION__);

	double std;
	int status = Funcs::get_std(arr1, std);
	are_equal(std, 2.76887462097);
}

void FuncsTest::test_std_arr2()
{
	print_test_name(__FUNCTION__);

	double std;
	int status = Funcs::get_std(arr2, std);
	are_equal(std, 2.82842712475);
}

void FuncsTest::test_std_l1()
{
	print_test_name(__FUNCTION__);

	double std;
	int status = Funcs::get_std(l1, std);
	are_equal(std, 2.90473750966);
}

void FuncsTest::test_std_l2()
{
	print_test_name(__FUNCTION__);

	double std;
	int status = Funcs::get_std(l2, std);
	are_equal(std, 2.90473750966);
}

void FuncsTest::test_median_v3()
{
	print_test_name(__FUNCTION__);

	double median;
	int status = Funcs::get_median(vect3, median);
	are_equal(median, 5.0);
}

void FuncsTest::test_median_v4()
{
	print_test_name(__FUNCTION__);

	double median;
	int status = Funcs::get_median(vect4, median);
	are_equal(median, 4.5);
}

void FuncsTest::test_median_v5()
{
	print_test_name(__FUNCTION__);

	double median;
	int status = Funcs::get_median(vect5, median);
	are_equal(median, 2);
}

void FuncsTest::test_median_arr1()
{
	print_test_name(__FUNCTION__);

	double median;
	int status = Funcs::get_median(arr1, median);
	are_equal(median, 4.5);
}

void FuncsTest::test_median_arr2()
{
	print_test_name(__FUNCTION__);

	double median;
	int status = Funcs::get_median(arr2, median);
	are_equal(median, 5.0);
}

void FuncsTest::test_median_l1()
{
	print_test_name(__FUNCTION__);

	double median;
	int status = Funcs::get_median(l1, median);
	are_equal(median, 5.5);
}

void FuncsTest::test_median_l2()
{
	print_test_name(__FUNCTION__);

	double median;
	int status = Funcs::get_median(l2, median);
	are_equal(median, 5.5);
}
