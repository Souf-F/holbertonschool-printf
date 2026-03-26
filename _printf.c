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
	va_list args;   /* liste des arguments variadiques */
	int count;      /* compteur de caractères imprimés */
	int index;      /* position actuelle dans la chaîne format */
	char *str;      /* pointeur pour stocker les chaînes passées en argument */

	index = 0;
	count = 0;

	/* initialise la liste d'arguments variadiques après le paramètre format */
	va_start(args, format);

	/* parcourt la chaîne format caractère par caractère */
	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			/* caractère normal : on l'écrit directement sur stdout */
			write(1, &format[index], 1);
			count++;
		}
		else if (format[index + 1] == '%')
		{
			/* double %% : on affiche un seul '%' littéral */
			write(1, &format[index], 1);
			count++;
			index++; /* saute le deuxième '%' */
		}
		else if (format[index + 1] == 'c')
		{
			/* spécificateur %c : affiche un caractère */
			count += print_char(va_arg(args, int));
			index++; /* saute le 'c' */
		}
		else if (format[index + 1] == 's')
		{
			/* spécificateur %s : affiche une chaîne de caractères */
			str = va_arg(args, char *);
			count += print_string(str);
			index++; /* saute le 's' */
		}
		index++; /* avance au caractère suivant dans format */
	}

	/* libère la liste d'arguments variadiques */
	va_end(args);

	return (count); /* retourne le nombre total de caractères imprimés */
}