#include <stdio.h>
/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to be implemented
 * Return: value of last digt of a number
 */
int print_last_digit(int n)
{
int last_digit = n % 10;
printf("%d", last_digit);
return (last_digit);
}
int main(void)
{
printf("%d%d%d%d", print_last_digit(98), print_last_digit(0),
print_last_digit(-1024), print_last_digit(-1024));
return (0);
}
