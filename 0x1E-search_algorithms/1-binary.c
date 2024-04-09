#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the array
 * @size: number of elements of the array
 * @value: the element to be searched in the array
 * Return: first index where value is located or if array is NULL return -1
 */

int binary_search(int *array, size_t size, int value)
{
	size_t mid, lt = 0;
	size_t rt = size - 1;

	while (rt >= lt)
	{
		printf("Searching in array: ");
		for (mid = lt; mid < rt; mid++)
		{
			printf("%d, ", array[mid]);
		}
		printf("%d\n", array[mid]);

		mid = lt + (rt - lt) / 2;

		if (array[mid] < value)
			lt = mid + 1;
		else if (array[mid] > value)
			rt = mid - 1;
		else
			return (mid);
	}

	if (!array)
	{
		return (-1);
	}

	return (-1);
}
