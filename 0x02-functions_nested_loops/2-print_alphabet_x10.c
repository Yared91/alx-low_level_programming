#include <stdio.h>
/**
 * main - writing a function that prints ten times the alphabet in lowercase
 * Return: 0 (Success)
 */
void print_alphabet_x10(void)
{
char c;
int i = 0;

while (i <= 9)
{
for (c = 'a'; c <= 'z'; c++);
{
putchar(c);
}
putchar('\n');
i++;
}
}

