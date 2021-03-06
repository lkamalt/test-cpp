#pragma once

#include "math.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <list>
#include <vector>

typedef std::string str;
typedef std::vector<str> strvec;
typedef std::vector<int> ivec;
typedef std::vector<double> dvec;
typedef std::vector<std::vector<double>> ddvec;

// Проверка равенства двух чисел
bool is_equal(double a, double b, double tolerance = 1e-5);

// Переводит массив строк в массив вещественных чисел
int vect_to_double(const strvec &vect_str, dvec &vect_res);
