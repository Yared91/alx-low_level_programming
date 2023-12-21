#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @size: size of array input
 * @key: key to get index of hash tables
 * Return: index of the key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
