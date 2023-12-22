#include "hash_tables.h"

/**
 * hash_table_get - given key, get value
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *top;

	/* find the index of key where in hash table it's */
	if (!ht || !key)
		return (NULL);

	/* traverse  linked list to find matching key for value */
	idx = key_index((const unsigned char *)key, ht->size);

	top = (ht->array)[idx];
	while (top != NULL && strcmp(top->key, key) != 0)
		top = top->next;
	if (!top)
		return (NULL);
	else
		return (top->value);
}
