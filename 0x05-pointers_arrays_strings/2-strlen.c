#include <stdio.h>
/**
 * _strlen - writing a function that returns the length of a string
 * @str: the length of the string
 * Return: the length of @str
 */
int _strlen(const char *str)
{
size_t length = 0;
while (*str++)
length++;
return (length);
}
