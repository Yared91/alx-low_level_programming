#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Writing a function that prints a name
 * @name: string input
 * @f: function input
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;
f(name);
}
