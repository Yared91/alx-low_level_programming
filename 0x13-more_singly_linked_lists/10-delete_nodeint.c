#include "lists.h"

/**
 * delete_nodeint_at_index - deletes nodes at index of listint_t linked list
 * @head: pointer input
 * @index: index input
 * Return: 1 Success, unless -1
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *node = *head;
listint_t *entity = NULL;
unsigned int b = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
free(node);
return (1);
}

while (b < index - 1)
{
if (!node || !(node->next))
return (-1);
node = node->next;
b++;
}
entity = node->next;
node->next = entity->next;
free(entity);

return (1);
}
