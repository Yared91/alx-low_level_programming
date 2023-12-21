#include "hash_tables.h"

/**
 * shash_table_create - makes arranged hash table
 * @size: size of the hash table
 * Return: NULL for failure, pointer to arraged table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table;
	unsigned long int index;

	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);
	shash_table->size = size;
	shash_table->shead = NULL;
	shash_table->stail = NULL;
	shash_table->array = malloc(sizeof(shash_table_t) * size);
	if (shash_table->array == NULL)
	{
		free(shash_table);
		return (NULL);
	}
	for (index = 0; index < size; index++)
	{
		shash_table->array[index] = NULL;
	}
	return (shash_table);
}

/**
 * make_shash_node - creates new shash node
 * @key: key for the node
 * @value: value for the node
 * Return: NULL for failure, otherwise new node
 */

shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
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
	node->next = node->snext = node->sprev = NULL;
	return (node);
}

/**
 * add_to_sorted_list - adds a node to arranged linked list
 * @table: the arranged shash table
 * @node: the node to add
 * Return: void
 */

void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *top;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	top = table->shead;
	while (top != NULL)
	{
		if (strcmp(node->key, top->key) < 0)
		{
			node->snext = top;
			node->sprev = top->sprev;
			top->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		top = top->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - adds an element to the shash table
 * @ht: pointer to shash table
 * @key: key to add input
 * @value: value with the key
 * Return: 0 for failure, otherwise 1
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *shash_node;
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
	shash_node = make_shash_node(key, value);
	if (shash_node == NULL)
		return (0);
	shash_node->next = ht->array[index];
	ht->array[index] = shash_node;
	add_to_sorted_list(ht, shash_node);
	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: pointer to hash table for retrieval
 * @key: key to find value
 * Return: NULL for failure, value associated with the element for success
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *top;

	if (ht == NULL || key == NULL || ht->array == NULL || ht->size == 0 ||
		strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	top = ht->array[index];
	while (top != NULL)
	{
		if (strcmp(top->key, key) == 0)
			return (top->value);
		top = top->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a shash table
 * @ht: pointer to the hash table
 * Return: void
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *top;
	char flow = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	top = ht->shead;
	while (top != NULL)
	{
		if (flow == 1)
			printf(", ");
		printf("'%s': '%s'", top->key, top->value);
		flow = 1;
		top = top->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse
 * @ht: pointer to the hash table
 * Return: void
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *top;
	char flow = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	top = ht->stail;
	while (top != NULL)
	{
		if (flow == 1)
			printf(", ");
		printf("'%s': '%s'", top->key, top->value);
		flow = 1;
		top = top->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a shash table
 * @ht: pointer to shash table
 * Return: void
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int index;
	shash_node_t *top;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (index = 0; index < ht->size; index++)
	{
		while (ht->array[index] != NULL)
		{
			top = ht->array[index]->next;
			free(ht->array[index]->key);
			free(ht->array[index]->value);
			free(ht->array[index]);
			ht->array[index] = top;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
