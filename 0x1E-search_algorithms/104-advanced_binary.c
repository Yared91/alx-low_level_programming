#include "search_algos.h"

/**
 * advanced_binary_recursive - Searches for a value in a sorted array
 * using binary search (recursive).
 * @array: Pointer to the first element of the sub-array to search.
 * @lt: Starting index of the sub-array.
 * @rt: Ending index of the sub-array.
 * @value: The value to search for.
 *
 * Return: Index where the value is located, or -1 if not found or at edges.
 */

int advanced_binary_recursive(int *array, size_t lt, size_t rt, int value)
{
	size_t middle;

	if (rt < lt)
		return (-1);

	printf("Searching in array: ");
	for (middle = lt; rt > middle; middle++)
	{
		printf("%d, ", array[middle]);
	}
	printf("%d\n", array[middle]);

	middle = lt + (rt - lt) / 2;

	if (array[middle] == value && (middle == lt || array[middle - 1] != value))
		return (middle);
	else if (array[middle] >= value)
	{
		return (advanced_binary_recursive(array, lt, middle, value));
	}
	else
	{
		return (advanced_binary_recursive(array, middle + 1, rt, value));
	}
}


/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: Pointer to the first element of the array to search
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index where the value is located (first occurrence)
 * otherwise -1 if not found or array is NULL/empty.
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
