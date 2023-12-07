#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: head list input
 * @n: value input
 * Return: address of new element
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *node;
dlistint_t *header;

node = malloc(sizeof(dlistint_t));
if (node == NULL)
return (NULL);

node->n = n;
node->prev = NULL;
header = *head;

if (header != NULL)
{
while (header->prev != NULL)
header = header->prev;
}
node->next = header;

if (header != NULL)
header->prev = node;

*head = node;

return (node);
}
