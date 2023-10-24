#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer input
 * Return: sum of data, unless 0
 */

int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *node = head;

while (node)
{
sum += node->n;
node = node->next;
}

return (sum);
}
