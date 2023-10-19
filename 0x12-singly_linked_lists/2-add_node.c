#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: the beginning of the node
 * @str: string input
 * Return: new element address
 */

list_t *add_node(list_t **head, const char *str)
{
list_t *temp;
int length = 0;

temp = malloc(sizeof(list_t));
if (temp == NULL)
return (NULL);

while (str[length])
length++;

temp->len = length;
temp->str = strdup(str);
temp->next = *head;
*head = temp;
return (temp);
}
