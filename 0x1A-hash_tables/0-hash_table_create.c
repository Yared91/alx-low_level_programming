#include "hash_tables.h"

/**
 * hash_table_create - Writing a function that creates a hash table
 * @size: size of array input
 * Return: NULL for error,  pointer to the newly created hash table for sucess
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashtable;
	unsigned long int x;

	hashtable = malloc(sizeof(hash_table_t));
	if (hashtable == NULL)
		return (NULL);

	hashtable->size = size;
	hashtable->array = malloc(sizeof(hash_node_t *) * size);

	if (hashtable->array == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
		hashtable->array[x] = NULL;

	return (hashtable);
}
