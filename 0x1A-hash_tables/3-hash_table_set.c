#include "hash_tables.h"

/**
 * create_and_add_node - malloc, set values, and insert node into hash table
 * @ht: hash table
 * @key: key; can not be empty string
 * @value: value associated with the key
 * @indx: index to insert in at hash table
 * Return: 1 if success, 0 if fail
 */
int create_and_add_node(hash_table_t *ht, const char *key, const char *value,
			unsigned long int indx)
{
	hash_node_t *newnode = NULL;
	char *a;
	char *c;

	newnode = malloc(sizeof(hash_node_t));
	if (!newnode)
		return (0);

	a = strdup(key);
	if (!a)
	{
		free(newnode);
		return (0);
	}

	c = strdup(value);
	if (!c)
	{
		free(a);
		free(newnode);
		return (0);
	}

	newnode->key = a;
	newnode->value = c;

	if ((ht->array)[indx] == NULL)
		newnode->next = NULL;
	else
		newnode->next = (ht->array)[indx];
	(ht->array)[indx] = newnode;

	return (1);
}

/**
 * hash_table_set - add element to hash table
 * @ht: hash table
 * @key: key; can not be empty string
 * @value: value value associated with the key
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int indx;
	hash_node_t *node = NULL;
	char *c;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
		return (0);

	indx = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[indx];
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;
	if (node != NULL)
	{
		c = strdup(value);
		if (!c)
			return (0);
		if (node->value)
			free(node->value);
		node->value = c;
		return (1);
	}

	return (create_and_add_node(ht, key, value, indx));
}
