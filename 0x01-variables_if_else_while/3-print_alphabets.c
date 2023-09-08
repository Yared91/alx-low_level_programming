#include <stdio.h>
/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
int lowerCase = 'a';
int upperCase = 'A';
while (lowerCase <= 'z')
{
putchar(lowerCase);
lowerCase++;
}
while (upperCase <= 'z')
{
putchar(upperCase);
upperCase++;
}
putchar('\n');
return (0);
}
