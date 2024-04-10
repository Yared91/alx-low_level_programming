#include "search_algos.h"

/**
 * _binary_search - searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in
 * @lt: A pointer for the first index in array
 * @value: The value to search for
 * @rt: Apointer for the end index of array
 * Return: if value found return index
 * otherwise if value not found and array NULL -1
 */

int _binary_search(int *array, size_t lt, size_t rt, int value)
{
	size_t middle;

	if (!array)
		return (-1);

	while (lt <= rt)
	{
		printf("Searching in array: ");

		for (middle = lt; middle < rt; middle++)
		{
			printf("%d, ", array[middle]);
		}

		printf("%d\n", array[middle]);

		/*Calculate middle index*/
		middle = lt + (rt - lt) / 2;

		if (array[middle] == value)
		{
			return (middle);
		}
		else if (array[middle] > value)
		{
			rt = middle - 1;
		}
		else
		{
			lt = middle + 1;
		}
	}

	return (-1);
}


/**
 * exponential_search - Searches for a value in a sorted array
 * @array: A Pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index where the value is located
 * otherwise -1 if not found or array is NULL.
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t index = 0;
	size_t new;

	if (!array)
	{
		return (-1);
	}

	/*Handle edge case where value is the first element*/

	if (array[0] != value)
	{
		for (index = 1; index < size && array[index] <= value; index *= 2)
		{
			/* Double the search range in each iteration */
			printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		}
	}

	/* Reduce search range to a sub-array based on the last checked index*/

	if (index < size)
	{
		new = index;
	}
	else
	{
		new = size - 1;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", index / 2, new);

	return (_binary_search(array, index / 2, new, value));
	/*Call binary search on the narrowed range*/
}
