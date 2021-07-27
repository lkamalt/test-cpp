class BinWriter;

#pragma once

#include "tools.h"

class BinWriter
{
public:
	BinWriter() = default;

	// Запись массива данных data в бинарный файл
	void write_data(str file_name, dvec data);
};
