#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer input
 * @n: integer input
 * Return: address of new element, if fails NULL
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *entry, *entity;
entry = malloc(sizeof(listint_t));

if (entry == NULL)
return (NULL);

entry->n = n;
entry->next = NULL;

if (*head == NULL)
*head = entry;

else
{
entity = *head;
while (entity->next != NULL)
entity = entity->next;
entity->next = entry;
}
return (*head);
}
