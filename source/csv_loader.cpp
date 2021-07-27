#include "csv_loader.h"

CSVLoader::CSVLoader() : has_diff_rows_count(false) {}

void CSVLoader::set_delimiter(str delimiter_)
{
	delimiter = delimiter_;
}

strvec CSVLoader::get_splitted(str s)
{
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	str subs;
	// Список подстрок строки s, разделенные заданным delimiter
	strvec s_splitted;

	while ((pos_end = s.find(delimiter, pos_start)) != str::npos) 
	{
		subs = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		s_splitted.push_back(subs);
	}

	subs = s.substr(pos_start);
	if (subs != delimiter && subs != "")
		s_splitted.push_back(subs);

	return s_splitted;
}

void CSVLoader::read_data(str file_name)
{
	try
	{
		read_data_in(file_name);
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
}

void CSVLoader::read_data_in(str file_name)
{
	std::ifstream f(file_name);
	// Считанная строка
	str s;
	// Список подстрок считанной строки s, разделенные заданным delimiter
	strvec s_splitted;
	// Список сконвертированных в число значений (1 строка из таблицы)
	dvec vect;
	// Пока не знаем размерность массива, куда будем записывать считанные данные
	bool has_dim = false;
	// Колчество столбцов на каждой итерации для проверки совпадения количества строк
	int cols_count = 0;
	// Встретили ли заголовок
	bool has_header = false;

	if (f.is_open())
		while (std::getline(f, s))
		{
			// Разбиваем строку на подстроки по разделителю
			s_splitted = get_splitted(s);
			// Конвертируем массив строк в массив чисел
			int status = vect_to_double(s_splitted, vect);

			if (status < 0 && !has_header)
			{
				header = s_splitted;
				has_header = true;
				continue;
			}

			// Когда в первый раз считали строку, узнали количество столбцов в файле
			// значит теперь можно установить размерность массива, хранящего считанные данные
			if (!has_dim)
			{
				// Запоминаем количество столбцов для проверки количества строк в каждом столбце
				cols_count = vect.size();
				// Выделяем память под основную структуру
				data.resize(vect.size());
				has_dim = true;
			}

			if (vect.size() != cols_count)
				has_diff_rows_count = true;

			// Заполнение массива считанными значениями
			for (int i = 0; i < vect.size(); i++)
				data[i].push_back(vect[i]);

			cols_count = vect.size();
		}

	f.close();

	// Запоминаем количество строк в каждой таблице
	rows_by_col.resize(data.size());
	for (int i = 0; i < data.size(); i++)
		rows_by_col[i] = data[i].size();

	if (has_diff_rows_count)
		throw std::exception("Different rows count\n");
}

int CSVLoader::get_columns_count()
{
	return data.size();
}

ivec CSVLoader::get_rows_count()
{
	if (!rows_by_col.empty())
		if (!has_diff_rows_count)
			return { rows_by_col[0] };
		else return rows_by_col;

	return { 0 };
}

strvec CSVLoader::get_header()
{
	return header;
}

ddvec CSVLoader::get_data()
{
	return data;
}

