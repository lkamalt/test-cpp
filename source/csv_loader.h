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
	// Количество строк по столбцам
	ivec rows_by_col;
	// Заголовок таблицы
	strvec header;

	// Разбивает строку на подстроки по разделителю delimiter
	// Возвращает список подстрок
	strvec get_splitted(str s);
	// Считывание данных из csv-файла с обработчиком ситуации неравенства размерности столбцов
	void read_data_in(str file_name);

public:
	CSVLoader();

	// Показывает одинаковая размерность у столбцов или нет
	bool has_diff_rows_count;

	// Установка разделителя csv-файла
	void set_delimiter(str delimiter);
	// Считывание данных из csv-файла
	void read_data(str file_name);
	// Возвращает количество столбцов в файле
	int get_columns_count();
	// Возвращает количество строк в файле
	// Если количество строк в столбцах разное, то вернет список из размерностей всех столбцов
	// Если одинаковое во всех столбцах, то вернет список из одного элемента - общей размерности всех столбцов
	ivec get_rows_count();
	// Возвращает заголовок таблицы
	strvec get_header();
	// Возвращает считанные данные
	ddvec get_data();
};
