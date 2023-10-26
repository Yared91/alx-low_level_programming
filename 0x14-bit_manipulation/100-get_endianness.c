#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: void
 */

int get_endianness(void)
{
int x;
char *y;

x = 1;
y = (char *) &x;

return (*y);
}
