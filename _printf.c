#include "main.h"
#include <unistd.h>
/**
 * _printf - produces output according to a format
 * @format: character string with directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{

	va_list args;
	int count;
	int index;

	index = 0;
	count = 0;

	va_start(args,  format);

	while (format[index] != '\0')
	{
		index++;
	}


	return (0);
}
