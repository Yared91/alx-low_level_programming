#include "hash_tables.h"

/**
 * hash_table_create - Writing a function that creates a hash table
 * @size: size of array input
 * Return: NULL for error,  pointer to the newly created hash table for sucess
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	hash_node_t **array;
	unsigned long int i = 0;

	if (size == 0)
		return (NULL);

	hash_table = malloc(sizeof(hash_table_t));
	if (!hash_table)
		return (NULL);

	array = malloc(sizeof(*array) * size);

	if (!array)
	{
		free(hash_table);
		return (NULL);
	}
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
	hash_table->size = size;
	hash_table->array = array;

	return (hash_table);
}
