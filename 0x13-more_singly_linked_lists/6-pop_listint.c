#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer input
 * Return: head node’s data, if empty 0
 */

int pop_listint(listint_t **head)
{
listint_t *new;
int digit;

if (!head || !*head)
return (0);

digit = (*head)->n;
new = (*head)->next;
free(*head);
*head = new;

return (digit);
}
