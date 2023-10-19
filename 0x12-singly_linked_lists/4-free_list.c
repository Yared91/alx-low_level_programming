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
list_t *entity;

while ((entity = head) != NULL)
{
head = head->next;
free(entity->str);
free(entity);
}
}
