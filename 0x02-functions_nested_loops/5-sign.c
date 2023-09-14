#include <stdio.h>
/**
 * print_sign - writing a function that prints the sign of a number
 * @n: the int to check
 * Return: 1, -1 or 0
 */
int print_sign(int n)
{
int test;

if (n > 0)
{
test = 1;
putchar('+');
}
else if (n == 0)
{
test = 0;
putchar('0');
}
else
{
test = -1;
putchar('-');
}
return (test);
}
