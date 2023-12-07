#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: head list input
 * Return: number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
int size = 0;

if (h == NULL)
{
return (size);
}
while (h->prev != NULL)
h = h->prev;

while (h != NULL)
{
size++;
h = h->next;
}

return (size);
}
