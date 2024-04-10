#include "search_algos.h"

/**
 * jump_list - Searches value in a sorted list of integers
 * @list: A pointer to the head of the list to search in
 * @size: The number of nodes in list
 * @value: The value to search for.
 *
 * Return: Index where the value is located, or -1 if not found or at edges.
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t j = 0;
	size_t diff_size = sqrt(size);
	listint_t *top, *new;

	if (!list || size == 0)
	{
		return (NULL);
	}

	/*Iterative jump phase*/
	for (top = new = list; new->index + 1 < size && new->n < value;)
	{
		top = new;
		/*Jump ahead in a loop*/
		for (j = j + diff_size; new->index < j; new = new->next)
		{
			if (new->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", new->index, new->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			top->index, new->index);

	for (; top->index < new->index && top->n < value; top = top->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", top->index, top->n);
	}
	printf("Value checked at index [%ld] = [%d]\n", top->index, top->n);

	/* Recursive linear search within the narrowed range */

	if (top->n == value)
		return (top);
	else
		return (NULL);
}
