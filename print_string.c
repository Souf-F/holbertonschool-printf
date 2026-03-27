#include "main.h"
#include <unistd.h>
/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *str)
{
	int index;
	int count;

	index = 0;
	count = 0;

	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		count++;
		index++;
	}
	return (count);
}
