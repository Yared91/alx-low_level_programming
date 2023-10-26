#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: number input
 * @index: index input
 * Return: 1 if success, unless -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int assign_bit;

if (index > (sizeof(unsigned long int) * 8 - 1))
return (-1);

assign_bit = 1 << index;
*n = *n | assign_bit;

return (1);
}
