#include <stdio.h>
/**
 * print_sign - writing a function that prints the sign of a number
 * @n: the int to check
 * Return: 1, -1 0r 0
 */
int print_sign(int n)
{
if (n > 0)
{
putchar('+');
return (1);
}
else if (n == 0)
{
putchar('0');
return (0);
}
else
{
putchar('-');
return (-1);
}
}
