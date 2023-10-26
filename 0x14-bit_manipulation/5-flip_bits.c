#include "main.h"

/**
 * flip_bits - returns the number of bits to flip to get from one to another
 * @n: 1st input
 * @m: 2nd input
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int c, numeratebit =  0;
unsigned long int entity;
unsigned long int diff = n ^ m;

for (c = 63; c >= 0; c--)
{
entity = diff >> c;
if (entity & 1)
numeratebit++;
}

return (numeratebit);
}
