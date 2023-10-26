#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary input
 * Return: converted number of 0
 */

unsigned int binary_to_uint(const char *b)
{
int c;
unsigned int digit;

digit = 0;

if (!b)
return (0);

for (c = 0; b[c] != '\0'; c++)
{
if (b[c] != '0' && b[c] != '1')
return (0);
}

for (c = 0; b[c] != '\0'; c++)
{
digit <<= 1;
if (b[c] == '1')
digit += 1;
}

return (digit);
}
