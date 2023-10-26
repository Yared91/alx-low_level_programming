#include "main.h"

/**
 * _raise - determines the base to the power of a number
 * @base: base input
 * @power: raise input
 * Return: the resultant of the calculation
 */

unsigned long int _raise(unsigned int base, unsigned int power)
{
unsigned long int digit;
unsigned int c;

digit = 1;

for (c = 1; c <= power; c++)
digit *= base;
return (digit);
}

/**
 * print_binary - prints the binary representation of a number
 * @n: number input
 * Return: void
 */

void print_binary(unsigned long int n)
{
unsigned long int factor, verify;
char indicator;

indicator = 0;
factor = _raise(2, sizeof(unsigned long int) * 8 - 1);

while (factor != 0)
{
verify = n & factor;
if (verify == factor)
{
indicator = 1;
_putchar('1');
}
else if (indicator == 1 || factor == 1)
{
_putchar ('0');
}
factor >>= 1;
}
}
