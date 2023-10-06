#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Writing a function that allocates memory using malloc
 * @b: input
 * Return: void
 */

void *malloc_checked(unsigned int b)
{
void *p;
p = malloc(b);
if (p == NULL)
exit(98);
return (p);
}
