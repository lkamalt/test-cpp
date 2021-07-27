#include "load_csv.h"

void CSVLoader::set_delimiter(str delimiter_)
{
	delimiter = delimiter_;
}

strvec CSVLoader::split(str s)
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

	s_splitted.push_back(s.substr(pos_start));

	return s_splitted;
}

void CSVLoader::read_data(str file_name)
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

	if (f.is_open())
		while (std::getline(f, s))
		{
			// Разбиваем строку на подстроки по разделителю
			s_splitted = split(s);
			// Конвертируем массив строк в массив чисел
			vect = vect_to_double(s_splitted);

			// Когда в первый раз считали строку, узнали количество столбцов в файле
			// значит теперь можно установить размерность массива, хранящего считанные данные
			if (!has_dim)
			{
				data.resize(vect.size());
				has_dim = true;
			}
			
			// Заполнение массива считанными значениями
			for (int i = 0; i < vect.size(); i++)
				data[i].push_back(vect[i]);
		}

	f.close();
}
