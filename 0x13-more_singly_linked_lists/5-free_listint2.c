#include "lists.h"

/**
 * free_listint2 - Writing a function that frees a listint_t list
 * @head: pointer input
 */

void free_listint2(listint_t **head)
{
listint_t *node;

if (head == NULL)
return;

while (*head)
{
node = (*head)->next;
free(*head);
*head = node;
}
head = NULL;
}
