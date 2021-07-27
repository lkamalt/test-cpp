#include "funcs_test.h"

#include "io_lib/csv_loader.h"
#include "io_lib/bin_loader.h"
#include "io_lib/bin_writer.h"

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

	str csv_file_name = "..//test//test.csv";
	str bin_file_name = "..//test//data.dat";

	CSVLoader loader;
	loader.set_delimiter(";");
	loader.read_data(csv_file_name);

	int cols = loader.get_columns_count();
	ivec rows = loader.get_rows_count();
	strvec header = loader.get_header();
	ddvec data = loader.get_data();

	BinWriter b_writer;
	b_writer.write_data(bin_file_name, data[1]);

	BinLoader b_loader;
	b_loader.set_data_size(data[0].size());
	b_loader.read_data(bin_file_name);
	dvec result = b_loader.get_data();
	for (double v : result)
		printf("%lf\n", v);

	system("pause");
	return 0;
}
