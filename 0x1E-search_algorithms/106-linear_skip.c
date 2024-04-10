#include "search_algos.h"

/**
 * linear_skip - Searches for an algorithm in a sorted singly
 *               linked list
 * @list: A pointer to the  head of the linked list to search.
 * @value: The value to search for
 * Return: If the value is not found or the head of the list is NUL
 *         Otherwise, a pointer to the first node where the value is located
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *top, *new;

	if (!list)
		return (NULL);

	for (top = new = list; new->next && new->n < value;)
	{
		top = new;

		if (new->express)
		{
			new = new->express;
			printf("Value checked at index [%ld] = [%d]\n", new->index, new->n);
		}
		else
		{
			while (new->next)
				new = new->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			top->index, new->index);

	for (; top->index < new->index && top->n < value; top = top->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", top->index, top->n);
	}

	printf("Value checked at index [%ld] = [%d]\n", top->index, top->n);

	if (top->n == value)
	{
		return (top);
	}
	else
	{
		return (NULL);
	}
}
