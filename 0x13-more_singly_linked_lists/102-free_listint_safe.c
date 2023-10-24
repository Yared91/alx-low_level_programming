#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer input
 * Return: size of the list
 */

size_t free_listint_safe(listint_t **h)
{
size_t dimen = 0;
int var;
listint_t *node;

if (!h || !*h)
return (0);

while (*h)
{
var = *h - (*h)->next;
if (var > 0)
{
node = (*h)->next;
free(*h);
*h = node;
dimen++;
}
else
{
free(*h);
*h = NULL;
dimen++;
break;
}
}
*h = NULL;
return (dimen);
}
