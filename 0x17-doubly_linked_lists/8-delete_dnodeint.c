#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * dlistint_t linked list
 * @head: head list input
 * @index: index of new node
 * Return: 1 for Success, -1 for Failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *a;
dlistint_t *b;
unsigned int j = 0;

a = *head;
if (a != NULL)

while (a->prev != NULL)
a = a->prev;

while (a != NULL)
{
if (j == index)
{
if (j == 0)
{
*head = a->next;
if (*head != NULL)
(*head)->prev = NULL;
}
else
{
b->next = a->next;
if (a->next != NULL)
a->next->prev = b;
}
free(a);
return (1);
}
b = a;
a = a->next;
j++;
}
return (-1);
}
