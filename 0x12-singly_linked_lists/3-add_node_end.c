#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node_end -  adds a new node at the end of a list_t list
 * @head: node end list input
 * @str: string input
 * Return: address of new element
 */

list_t *add_node_end(list_t **head, const char *str)
{
list_t *item, *entry;
size_t h;

item = malloc(sizeof(list_t));
if (item == NULL)
return (NULL);
item->str = strdup(str);

for (h = 0; str[h]; h++)
;

item->len = h;
item->next = NULL;
entry = *head;

if (entry == NULL)
{
*head = item;
}
else
{
while (entry->next != NULL)
entry = entry->next;
entry->next = item;
}
return (*head);
}

