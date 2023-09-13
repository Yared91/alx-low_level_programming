#include <stdio.h>
/**
 * print_to_98 - prints all natural numbers form n to 98
 * @n: from where printing number starts
 * Return: returns nothing
 */
void print_to_98(int n)
{
if (n <= 98)
{
for (n = n; n <= 97; n++)
printf("%d, ", n);
}
else
for (n = n; n > 98; n--)
printf("%d, ", n);
printf("98\n");
}
