#include <stdio.h>
/**
 * print_sign - writing a function that prints the sign of a number
 * @n: the int to check
 * Return: 1 for positive value, -1 for negative value or 0 for zero
 */
int print_sign(int n)
{
if (n > 0)
{
putchar('+');
return (1);
}
else if (n < 0)
{
putchar('-');
return (-1);
}
else if (n == 0)
{
putchar(48);
}
return (0);
}
