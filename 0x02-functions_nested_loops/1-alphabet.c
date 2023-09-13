#include <stdio.h>
/**
 * main - Writing a function that prints alphabets in lowercase
 * Return: 0 (Success)
 */
void print_alphabet(void)
{
char c;

for (c = 'a'; c <= 'z'; c++ )
{
putchar(c);
}
putchar('\n');
}
