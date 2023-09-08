#include <stdio.h>
/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
int LOWER = 'a';
int UPPER = 'A';
while (LOWER <= 'z')
{
putchar(LOWER);
LOWER++;
}
while (UPPER <= 'z')
{
putchar(UPPER);
UPPER++;
}
putchar('\n');
return (0);
}
