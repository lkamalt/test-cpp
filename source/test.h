class Test;

#pragma once

#include "tools.h"

class Test
{
public:
	// Функции для проверки равенства значений checked_value и standard_value с заданной точностью tolerance
	static void are_equal(double checked_value, double standard_value, double tolerance = 1e-6);

	// Вывод названия теста
	static void print_test_name(str tn = "");
	// Вывод результатов тестирования
	static void print_results();

private:
	// Общее количество тестов
	static int total_count;
	// Количество успешно пройденных тестов
	static int passed_count;
	// Количество непройденных тестов
	static int failed_count;
	// Список с названиями непройденных тестов
	static strvec failed_test_names;
	// Название теста
	static str test_name;

	// Функция проверки условия
	static void check_cond(bool cond);
};
