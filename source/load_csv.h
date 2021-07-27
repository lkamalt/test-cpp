class CSVLoader;

#pragma once

#include "tools.h"

class CSVLoader
{
private:
	// Загруженные данные
	// Каждая строка - столбец из файла
	ddvec data;
	// Разделитель данных в csv-файле
	str delimiter;

	// Разбивает строку на подстроки по разделителю delimiter
	// Возвращает список подстрок
	strvec split(str s);

public:
	CSVLoader() = default;

	// Установка разделителя csv-файла
	void set_delimiter(str delimiter);
	// Считывание данных из csv-файла
	void read_data(str file_name);

	// Возвращает количество столбцов в файле
	int get_columns_count();
	// Возвращает количество строк в файле
	int get_rows_count();
};

