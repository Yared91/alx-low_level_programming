#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer input
 * Return: pointer to 1st node
 */

listint_t *reverse_listint(listint_t **head)
{
listint_t *back = NULL;
listint_t *forw = NULL;

while (*head)
{
forw = (*head)->next;
(*head)->next = back;
back = *head;
*head = forw;
}
*head = back;
return (*head);
}
