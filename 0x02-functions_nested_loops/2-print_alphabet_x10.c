#include <stdio.h>
/**
 * print_alphabet_x10 - writing a function that prints 10x the alphabet
 * Return: void
 */
void print_alphabet_x10(void)
{
char num, letter;

for (num = 0; num <= 9; num++)
{
for (letter = 'a'; letter <= 'z'; letter++)
{
putchar(letter);
}
putchar('\n');
}
}
