class BinLoader;

#pragma once

#include "tools.h"

class BinLoader
{
private:
	// Список, который хранит загруженные данные
	dvec data;

public:
	BinLoader() = default;

	// Загрузка данных из бинарного файла
	void read_data(str file_name);
	// Задать длину массива - переменной с результатом 
	void set_data_size(int size);
	// Возвращает список загруженных данных
	dvec get_data();
};
