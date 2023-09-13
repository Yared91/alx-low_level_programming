#include <stdio.h>
/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to be implemented
 * Return: value of last digt of a number
 */
int print_last_digit(int n)
{
int k;

k = n % 10;
if (n < 0)
k = -k;
putchar(k + '0');
return (k);
}
