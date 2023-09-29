#include "main.h"
#include <stdio.h>

int check_prime(int n, int i);

/**
 * is_prime_number - Returns if a number is prime
 * @n: input
 * Return: integer
 */

int is_prime_number(int n)
{
return (check_prime(n, 1));
}

/**
 * check_prime - checks if a number is prime
 * @n: number to be checked
 * @i: iteration times
 * Return: 1 for prime or 0 for composite
 */

int check_prime(int n, int i)
{
if (n <= 1)
return (0);
if (n % i == 0 && i > 1)
return (0);
if ((n / i) < i)
return (1);
return (check_prime(n, i + 1));
}
