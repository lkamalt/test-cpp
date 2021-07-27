#include "tools.h"

namespace Funcs
{
	// Вычисление среднего арифметического списка чисел arr, результат записывается в result
	template<typename Type>
	int get_mean(Type arr, double &result)
	{
		if (arr.empty())
			return -1;

		double sum = std::accumulate(arr.begin(), arr.end(), 0.0);;
		result = sum / arr.size();

		return 0;
	}

	// Вычисление среднеквадратичного отклонения списка чисел arr, результат записывается в result
	template<typename Type>
	int get_std(Type arr, double &result)
	{
		if (arr.empty())
			return -1;

		double mean;
		int status = Funcs::get_mean(arr, mean);
		if (status < 0)
			return -1;

		double sq_sum = std::inner_product(arr.begin(), arr.end(), arr.begin(), 0.0);;
		result = sqrt(sq_sum / arr.size() - mean * mean);

		return 0;
	}

	// Вычисление медианы списка чисел, результат записывается в result
	template<typename Type>
	int get_median(Type arr, double &result)
	{
		if (arr.empty())
			return -1;

		if (arr.size() == 1)
		{
			result = arr[0];
			return 0;
		}

		// Сортируем массив по возрастанию
		std::sort(arr.begin(), arr.end());

		// Индекс элемента, расположенного в середине списка
		int mid_idx = static_cast<int>(arr.size() / 2);

		// Если в списке нечетное число элементов, то результат = элемент в середине отсортированного списка
		if (arr.size() % 2 != 0)
		{
			result = arr[mid_idx];
			return 0;
		}

		// Если в списке четное число элементов, то результат = полусумма двух средних чисел
		result = 0.5 * (arr[mid_idx - 1] + arr[mid_idx]);
		return 0;
	}
}
