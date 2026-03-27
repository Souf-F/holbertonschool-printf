#include "main.h"
#include <unistd.h>
/**
 * print_string - prints a string
 * @str: string to print
 * Return: number of characters printed
 *
 */
int print_string(char *str)
{
	int index;

	if (!str)
	{
		str = "(null)";
		write(1, str, 6);
		return (6);
	}
	index = 0;

	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}
