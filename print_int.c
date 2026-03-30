#include "main.h"
#include <unistd.h>
/**
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += print_char('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_int(num / 10);

	count += print_char((num % 10) + '0');

	return (count);
}
