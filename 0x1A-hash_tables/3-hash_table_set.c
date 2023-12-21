#include "hash_tables.h"

/**
 * make_hash_node - creates new hash node
 * @key: key for the node
 * @value: value for the node
 * Return: NULL for failure, otherwise new node
 */

hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: pointer to hash table
 * @key: key to add input
 * @value: value with the key
 * Return: 0 for failure, otherwise 1
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hash_node;
	char *val_dup;
	unsigned long int index;

	if (ht == NULL || key == NULL || ht->array == NULL || ht->size == 0 ||
		strlen(key) == 0 || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	while (ht->array[index] != NULL)
	{
		if (strcmp(ht->array[index]->key, key) == 0)
		{
			val_dup = strdup(value);
			if (val_dup == NULL)
				return (0);
			free(ht->array[index]->value);
			ht->array[index]->value = val_dup;
			return (1);
		}
		ht->array[index] = ht->array[index]->next;
	}
	hash_node = make_hash_node(key, value);
	if (hash_node == NULL)
		return (0);
	hash_node->next = ht->array[index];
	ht->array[index] = hash_node;
	return (1);
}
