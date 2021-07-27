#include "bin_loader.h"

void BinLoader::read_data(str file_name)
{
	std::fstream file(file_name, std::ios::in | std::ios::binary);
	file.seekg(0);
	file.read((char*)data.data(), data.size() * sizeof(double));
	file.close();
}

void BinLoader::set_data_size(int size)
{
	data.resize(size);
}

dvec BinLoader::get_data()
{
	return data;
}
