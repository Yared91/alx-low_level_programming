#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: head list input
 * @n: value input
 * Return: address of new element
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *node;
dlistint_t *header;

node = malloc(sizeof(dlistint_t));
if (node == NULL)
return (NULL);

node->n = n;
node->next = NULL;
header = *head;

if (header != NULL)
{
while (header->next != NULL)
header = header->next;
header->next = node;
}
else
{
*head = node;
}
node->prev = header;
return (node);
}
