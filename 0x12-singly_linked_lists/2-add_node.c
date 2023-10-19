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
list_t *node;
int dimension = 0;

node = malloc(sizeof(list_t));
if (node == NULL)
return (NULL);

while (str[dimension])
dimension++;

node->len = dimension;
node->str = strdup(str);
node->next = *head;
*head = node;
return (node);
}
