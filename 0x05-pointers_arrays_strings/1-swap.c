#include <stdio.h>
/**
 * swap_int - writing a function that swaps the values of 2 integers
 * @a: the 1st integer to be swaped
 * @b: the 2nd integer to be swaped
 * Return: void
 */
void swap_int(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
