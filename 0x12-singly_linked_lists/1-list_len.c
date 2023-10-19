#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - displays number of elements in a linked list_t list
 * @h: list input
 * Return: number of elements
 */

size_t list_len(const list_t *h)
{
size_t list = 0;
for (h)
{
h = h->next;
list++;
}
return (list);
}
