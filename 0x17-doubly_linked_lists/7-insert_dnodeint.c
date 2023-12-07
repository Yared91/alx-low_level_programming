#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: head list input
 * @idx: index of new node
 * @n: value of new node
 * Return: address of new node
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *node;
dlistint_t *header;
unsigned int j;

node = NULL;
if (idx == 0)
node = add_dnodeint(h, n);
else
{
header = *h;
j = 1;

if (header != NULL)
while (header->prev != NULL)
header = header->prev;
while (header != NULL)
{
if (j == idx)
{
if (header->next == NULL)
node = add_dnodeint_end(h, n);
else
{
node = malloc(sizeof(dlistint_t));
if (node != NULL)
{
node->n = n;
node->next = header->next;
node->prev = header;
header->next->prev = node;
header->next = node;
}
}
break;
}
header = header->next;
j++;
}
}
return (node);
}
