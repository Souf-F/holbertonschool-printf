#include "main.h" /* mon header avec les prototypes */
#include <unistd.h> /* pour utiliser write */
/**
 * print_char - prints a character
 * @c: character to print
 *
 * Return: number of characters printed
 */
int print_char(char c) /* je recois un caractere en parametre */
{
	write(1, &c, 1); /* j'affiche le caractere sur le terminal */
	return (1); /* je retourne 1 car j'ai affiche 1 seul caractere */
}
