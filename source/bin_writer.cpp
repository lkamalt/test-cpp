#include "bin_writer.h"

void BinWriter::write_data(str file_name, dvec data)
{
	std::fstream file(file_name, std::ios::out | std::ios::binary);
	file.seekp(0);
	file.write((char*)data.data(), data.size() * sizeof(double));
	file.close();
}
