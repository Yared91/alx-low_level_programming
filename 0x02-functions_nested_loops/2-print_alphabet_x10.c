#include <stdio.h>
/**
 * print_alphabet_x10 - writing a function that prints 10x the alphabet
 * Return: void
 */
void print_alphabet_x10(void)
{
int i, c;

for (i = 0; i < 10; i++)
{
	for (c = 'a'; c <= 'z'; c++)
		_putchar(c);
}
_putchar('\n');
}

