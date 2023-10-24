#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer input
 * Return: address of the pointer, Unless NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
listint_t *back = head;
listint_t *front = head;

if (!head)
return (NULL);

while (back && front && front->next)
{
front = front->next->next;
back = back->next;

if (front == back)
{
back = head;
while (back != front)
{
back = back->next;
front = front->next;
}
return (front);
}
}
return (NULL);
}
