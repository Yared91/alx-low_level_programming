#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: If value found return index
 * otherwise if value not fund and array is NULL -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t index;
	size_t below = 0;
	size_t above = size - 1;

	if (!array)
	{
		return (-1);
	}
	
	while (below <= above)
	{
		index = below + (((double)(above - below) / (array[above] -
				array[below])) * (value - array[below]));

		if (index < size)
			printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", index);
			break;
		}

		if (array[index] == value)
			return (index);
		else if (array[index] > value)
			above = index - 1;
		else
			below = index + 1;
	}

	return (-1);
}
