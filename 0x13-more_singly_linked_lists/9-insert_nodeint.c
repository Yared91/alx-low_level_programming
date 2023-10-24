#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer input
 * @idx: index input
 * @n: data input
 * Return: pointer to new node unless NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int b;
listint_t *entry;
listint_t *node = *head;

entry = malloc(sizeof(listint_t));
if (!entry || !head)
return (NULL);

entry->n = n;
entry->next = NULL;

if (idx == 0)
{
entry->next = *head;
*head = entry;
return (entry);
}

for (b = 0; node && b < idx; b++)
{
if (b == idx - 1)
{
entry->next = node->next;
node->next = entry;
return (entry);
}
else
node = node->next;
}
return (NULL);
}
