#include <unistd.h>
/**
 * _putchar.c - writes the character c to stout
 * @c: The character to print
 * Return: 1 (Success)
 * -1 (error)
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}


