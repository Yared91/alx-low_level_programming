#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: head list input
 * @index: index of nth node input
 * Return: nth node
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int j = 0;

if (head == NULL)
return (NULL);

while (head->prev != NULL)
head = head->prev;

while (head != NULL)
{
if (j == index)
break;
head = head->next;
j++;
}
return (head);
}
