#include "main.h"
#include <stdio.h>

/**
 * main - prints the number of arguments
 * @argc: input
 * @argv: input
 * Return: void
 */
int main(int argc, char *argv[])
{
(void) argv;
printf("%d\n", argc - 1);
return (0);
}
