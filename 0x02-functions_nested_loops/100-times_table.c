#include <stdio.h>
/**
 * print_times_table - Prints the times table of the input,
 * starting with 0.
 * @n: The value of the times table to be printed.
 */
void print_times_table(int n)
{
int num, mult, prod;

if (n >= 0 && n <= 15)
{
for (num = 0; num <= n; num++)
{
putchar('0');
for (mult = 1; mult <= n; mult++)
{
putchar(',');
putchar(' ');
prod = num * mult;
if (prod <= 99)
putchar(' ');
if (prod <= 9)
putchar(' ');
if (prod >= 100)
{
putchar((prod / 100) + '0');
putchar(((prod / 10)) % 10 + '0');
}
else if (prod <= 99 && prod >= 10)
{
putchar((prod / 10) + '0');
}
putchar((prod % 10) + '0');
}
putchar('\n');
}
}
}

