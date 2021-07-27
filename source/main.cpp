#include "funcs_test.h"

int main(int argc, char* argv[])
{
	FuncsTest::test_mean_v1();
	FuncsTest::test_mean_v2();

	FuncsTest::test_std_v1();
	FuncsTest::test_std_v2();

	FuncsTest::test_median_v3();
	FuncsTest::test_median_v4();
	FuncsTest::test_median_v5();

	Test::print_results();

	system("pause");
	return 0;
}
