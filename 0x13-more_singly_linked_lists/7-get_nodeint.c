#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer input
 * @index: index of node
 * Return: nth node, if not NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int _ = 0;
listint_t *node = head;

while (node && _ < index)
{
node = node->next;
_++;
}
return (node ? node : NULL);
}
