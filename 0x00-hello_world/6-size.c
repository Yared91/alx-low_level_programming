#include <stdio.h>
/**
 * main - A program that prints the size of various computer types
 * Return: 0 (Success)
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;
printf("Size_of_achar: %lu  byte(s)\n", (unsigned long)sizeof(a));
printf("Size_of_anint: %lu  byte(s)\n", (unsigned long)sizeof(b));
printf("Size_of_along int: %lu  byte(s)\n", (unsigned long)sizeof(c));
printf("Size_of_along long int: %lu  byte(s)\n", (unsigned long)sizeof(d));
printf("Size_of_afloat: %lu  byte(s)\n", (unsigned long)sizeof(f));
return (0);
}

