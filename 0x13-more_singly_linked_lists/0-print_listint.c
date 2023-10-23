#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Writing function that prints all the elements
 * of a listint_t list
 * @h: pointer input
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
size_t element = 0;

if (h == NULL)
return (0);

for (element = 0; h != NULL; element++)
{
printf("%d\n", h->n);
h = h->next;
}

return (element);
}
