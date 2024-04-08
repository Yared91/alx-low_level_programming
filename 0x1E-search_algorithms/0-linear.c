#include "search_algos.h"

/**
 * linear_search - searches the array sequencially
 * @array: pointer to the array
 * @size: number of elements of the array
 * @value: the element to be searched in the array
 * Return: first index where value is located or if array is NULL return -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t index = 0;

	while (index < size)
	{
		printf("Value checked array[%ld] = [%d]\n", index,
				array[index]);
		if (array[index] == value)
		{
			return (index);
		}
		index++;
	}

	if (!array)
	{
		return (-1);
	}

	return (-1);
}
