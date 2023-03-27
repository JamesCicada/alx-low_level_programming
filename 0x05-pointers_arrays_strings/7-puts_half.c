#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: Pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i, j, len = 0;
	/* Get the length of the string */
	while (str[len] != '\0')
		len++;

	/* If odd length, print last n characters */
	if (len % 2 == 1)
		j = (len - 1) / 2;
	else
		j = len / 2;

	/* Print second half of string */
	for (i = j; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

