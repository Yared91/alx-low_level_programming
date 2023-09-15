#include "main.h"
/**
 * print_sign - writing a function that prints the sign of a number
 * @n: number to be implemented
 * Return: 0 for zero, 1 for positve value, -1 for negative value
 */
int print_sign(int n)
{

if (n > 0)
{
_putchar(43);
return (1);
}
else if (n < 0)
{
_putchar(45);
return (-1);
}
else
{
_putchar(48);
return (0);
}
}
