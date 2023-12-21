#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: pointer to the hash table
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *top;
	char flow = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		top = ht->array[index];
		while (top != NULL)
		{
			if (flow == 1)
				printf(", ");
			printf("'%s': '%s'", top->key, top->value);
			flow = 1;
			top = top->next;
		}
	}
	printf("}\n");
}
