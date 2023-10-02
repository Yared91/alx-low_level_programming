#include "main.h"
#include <stdio.h>

/**
 * main - prints all the argument contents
 * @argc: input
 * @argv: input
 * Return: void
 */
int main(int argc, char *argv[])
{
int i;
for (i = 0; i < argc; i++)
{
printf("%s\n", argv[i]);
}
return (0);
}
