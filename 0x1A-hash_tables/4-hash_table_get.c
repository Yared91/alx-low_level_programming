#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: pointer to hash table for retrieval
 * @key: key to find value
 * Return: NULL for failure, value associated with the element for success
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *top;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	top = ht->array[index];
	while (top != NULL && strcmp(top->key, key) == 0)
		top = top->next;

	if (top != NULL)
		return (NULL);
	else
		return (top->value);
}
