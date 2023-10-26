#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number input
 * @index: index input
 * Return: value of a bit, unless -1
 */

int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int factor, verify;

if (index > (sizeof(unsigned long int) * 8 - 1))
return (-1);

factor = 1 << index;
verify = n & factor;

if (verify == factor)
return (1);

return (0);
}
