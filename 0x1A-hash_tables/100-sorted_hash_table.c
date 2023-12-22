#include "hash_tables.h"

/**
 * shash_table_create - create sorted hash table
 * @size: size of array
 * Return: pointer to table; NULL if error
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **array;
	unsigned long int i = 0;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);
	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(ht);
		return (NULL);
	}
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}

	ht->size = size;
	ht->array = array;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_to_sorted_list - compare and insert node into list for printing
 * @ht: sorted hash table
 * @node: node to insert
 * Return: 1 if success, 0 if fail
 */
int insert_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *top;

	/* if empty hash table, initialize head and tail nodes */
	if (!(ht->shead))
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	if (strcmp(node->key, (ht->shead)->key) <= 0) /* insert at beginning */
	{
		node->snext = ht->shead;
		(ht->shead)->sprev = node;
		ht->shead = node;
	}
	else if (strcmp(node->key, (ht->stail)->key) > 0) /* insert at end */
	{
		node->sprev = ht->stail;
		(ht->stail)->snext = node;
		ht->stail = node;
	}
	else /* insert in middle */
	{
		top = ht->shead;
		while (top->snext && strcmp(node->key, (top->snext)->key) > 0)
			top = top->snext;
		node->snext = top->snext;
		node->sprev = top;
		(top->snext)->sprev = node;
		top->snext = node;
	}
	return (1);
}

/**
 * create_and_add_node - allocates, set values, and insert node into hash table
 * @ht: sorted hash table
 * @key: key; can't be empty string
 * @value: value
 * @idx: index to insert in at hash table
 * Return: 1 if success, 0 if fail
 */
int create_and_add_node(shash_table_t *ht, const char *key, const char *value,
			unsigned long int idx)
{
	shash_node_t *newnode = NULL;
	char *ky;
	char *val;
	(void) idx;
	newnode = malloc(sizeof(shash_node_t));
	if (!newnode)
		return (0);

	ky = strdup(key);
	if (!ky)
	{
		free(newnode);
		return (0);
	}

	val = strdup(value);
	if (!val)
	{
		free(ky);
		free(newnode);
		return (0);
	}

	newnode->key = ky;
	newnode->value = val;
	newnode->next = NULL;
	newnode->sprev = NULL;
	newnode->snext = NULL;

	if ((ht->array)[idx] == NULL)
		newnode->next = NULL;
	else
		newnode->next = (ht->array)[idx];
	(ht->array)[idx] = newnode;

	return (insert_to_sorted_list(ht, newnode));
}

/**
 * shash_table_set - add element to sorted hash table
 * @ht: hash table
 * @key: key; can nott be empty string
 * @value: value
 * Return: 1 if success, 0 if fail
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	/* get index */
	/* if key already exists, update value and return */
	/* else create node */
	/* set ht idx ptr to node; else put in sorted linked list if collision*/

	unsigned long int idx;
	shash_node_t *node = NULL;
	char *val;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[idx];
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;
	if (node != NULL)
	{
		val = strdup(value);
		if (!val)
			return (0);
		if (node->value)
			free(node->value);
		node->value = val;
		return (1);
	}

	return (create_and_add_node(ht, key, value, idx));
}

/**
 * shash_table_get - given key, get value
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *tmp;

	/* find index in hash table where key is */
	/* look through linked list to find matching key for value */

	if (!ht || !key)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);

	tmp = (ht->array)[idx];
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	else
		return (tmp->value);
}

/**
 * shash_table_print - print key/values of hash table in ascending order
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *delim = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	node = ht->shead;
	while (node)
	{
		printf("%s'%s': '%s'", delim, node->key, node->value);
		delim = ", ";
		node = node->snext;
	}
	puts("}");
}

/**
 * shash_table_print_rev - print key/values of sorted ht in reverse order
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *delim = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	node = ht->stail;
	while (node)
	{
		printf("%s'%s': '%s'", delim, node->key, node->value);
		delim = ", ";
		node = node->sprev;
	}
	puts("}");
}

/**
 * shash_table_delete - free and delete sorted hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int idx = 0;
	shash_node_t *node, *next;

	if (!ht)
		return;

	if (!(ht->array))
	{
		free(ht);
		return;
	}

	while (idx < ht->size)
	{
		node = (ht->array)[idx];
		while (node)
		{
			next = node->next;
			if (node->key)
				free(node->key);
			if (node->value)
				free(node->value);
			node->key = NULL;
			node->value = NULL;
			free(node);
			node = next;
		}
		idx++;
	}
	free(ht->array);
	free(ht);
}
