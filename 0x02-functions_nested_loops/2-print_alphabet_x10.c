#include <stdio.h>
/**
 * main - writing a function that prints ten times the alphabet in lowercase
 * Return: void
 */
void print_alphabet_x10(void)
{
char c;
int i;
i = 0;
while (i < 10)
{
for (c = 'a'; c <= 'z'; c++);
putchar(c);
putchar('\n');
i++;
}
}

