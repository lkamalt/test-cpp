class FuncsTest;

#pragma once

#include "tools.h"
#include "test.h"

class FuncsTest : public Test
{
public:
	static dvec vect0;
	static dvec vect1;
	static dvec vect2;
	static dvec vect3;
	static dvec vect4;
	static dvec vect5;
	static dvec vect6;

	static void test_mean_v1();
	static void test_mean_v2();

	static void test_std_v1();
	static void test_std_v2();

	static void test_median_v3();
	static void test_median_v4();
	static void test_median_v5();
};
