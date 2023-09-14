#include <stdio.h>
/**
 * print_sign - writing a function that prints the sign of a number
 * @n: number to be implemented
 * Return: 0 for zero, 1 for positve value, -1 for negative value
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
