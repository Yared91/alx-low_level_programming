#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - counts the number of unique nodes
 * @head: pointer input
 * Return: number of unique nodes, Unless 0
 */

size_t looped_listint_len(const listint_t *head)
{
const listint_t *count, *current;
size_t temp = 1;

if (head == NULL || head->next == NULL)
return (0);

count = head->next;
current = (head->next)->next;

while (current)
{
if (count == current)
{
count = head;
while (count != current)
{
temp++;
count = count->next;
current = current->next;
}
count = count->next;
while (count != current)
{
temp++;
count = count->next;
}
return (temp);
}
count = count->next;
current = (current->next)->next;
}
return (0);
}

/**
 * print_listint_safe -  prints a listint_t linked list
 * @head: pointer input
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
size_t entry, entity = 0;
entry = looped_listint_len(head);

if (entry == 0)
{
for (; head != NULL; entry++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (entity = 0; entity < entry; entity++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
printf("-> [%p] %d\n", (void *)head, head->n);
}
return (entry);
}
