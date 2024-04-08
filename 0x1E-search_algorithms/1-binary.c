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
	size_t index, lt = 0;
	size_t rt = size - 1;

	while (rt >= lt)
	{
		printf("Searching in array: ");
		for (index = lt; index < rt; index++)
		{
			printf("%d, ", array[index]);
		}
		printf("%d\n", array[index]);

		index = lt + (rt - lt) / 2;

		if (array[index] < value)
			lt = index + 1;
		else if (array[index] > value)
			rt = index - 1;
		else
			return (index);
	}

	if (!array)
	{
		return (-1);
	}

	return (-1);
}
