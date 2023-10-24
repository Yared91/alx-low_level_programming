#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer input
 * @n: integer input
 * Return: address of new element, if fails NULL
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *entry;
entry = malloc(sizeof(listint_t));

if (entry == NULL)
return (NULL);

entry->n = n;
entry->next = *head;
*head = entry;

return (entry);
}
