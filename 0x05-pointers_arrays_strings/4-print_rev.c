#include "main.h"

/**
 * print_rev - Prints a string in reverse order.
 *
 * @s: The string to be printed.
 *
 * Return: void.
 */
void print_rev(char *s)
{
	int i = 0, len = 0;
	
	/* Calculate length of the string */
	while (*(s + i))
	{
		len++;
		i++;
	}

	/* Print the string in reverse */
	for (i = len - 1; i >= 0; i--)
		_putchar(*(s + i));

	_putchar('\n');
}

