#include <stdio.h>
/**
 * main - writing a function that prints the sign of a number
 * Return: 1 for positive value, -1 for negative value or 0 for zero
 */
int print_sign(int n)
{
if (n > 0)
{
putchar(43);
return (1);
}
else if (n < 0)
{
putchar(45);
return (-1);
}
else
{
putchar(48);
return (0);
}
}
