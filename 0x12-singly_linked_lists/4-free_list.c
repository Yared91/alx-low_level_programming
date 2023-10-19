#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_list - Writing a function that frees a list_t list
 * @head: list input
 * Return: void
 */

void free_list(list_t *head)
{
list_t *current_node;

while ((current_node = head) != NULL)
{
head = head->next;
free(current_node->str);
free(current_node);
}
}
