#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Prints a text according number
 * Return: 0 (Success)
 */
int main(void)
{
int n, lastd;
srand(time(0));
n = rand() - RAND_MAX / 2;
lastd = n % 10;
if (lastd > 5)
{
printf("Last digit of %d is %s and is greater than 5\n", n, "8");
}
else if (lastd == 0)
{
printf("Last digit of %d is %s and is 0\n", n, "0");
}
else if (lastd < 6 && lastd != 0)
{
printf("Last digit of %d is %s and is less than 6 and not 0\n",
n, "-8");
}
return (0);
}
