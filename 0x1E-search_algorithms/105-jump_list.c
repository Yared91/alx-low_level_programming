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
size_t i = 0;
size_t jump_size = sqrt(size);
listint_t *node, *step;

if (list == NULL || size == 0)
{
return (NULL);
}

/*Iterative jump phase*/
for (node = step = list; step->index + 1 < size && step->n < value;)
{
node = step;
/*Jump ahead in a loop*/
for (i = i + jump_size; step->index < i; step = step->next)
{
if (step->index + 1 == size)
break;
}
printf("Value checked at index [%ld] = [%d]\n", step->index, step->n);
}
printf("Value found between indexes [%ld] and [%ld]\n",
		node->index, step->index);

for (; node->index < step->index && node->n < value; node = node->next)
{
printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
}
printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

/* Recursive linear search within the narrowed range */
if (node->n == value)
return (node);
else
return (NULL);
}
