#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: If the value is found return the index
 * otherwise If value is not found or array is NULL -1
 */

int jump_search(int *array, size_t size, int value)
{
	size_t top, above;
	size_t below = top = 0;

	if (!array || size == 0)
	{
		return (-1);
	}

	above = sqrt(size);

	while (top < size && array[top] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", top, array[top]);
		below = top;
		top = top + above;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", below, top);

	if (top < size - 1)
	{
		top = top;
	}
	else
	{
		top = size - 1;
	}

	for (; below < top && array[below] < value; below++)
	{
		printf("Value checked array[%ld] = [%d]\n", below, array[below]);
	}

	printf("Value checked array[%ld] = [%d]\n", below, array[below]);
	
	if (array[below] == value)
	{
		return ((int)below);
	}
	else
	{
		return (-1);
	}
}
