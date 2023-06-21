#include <stdio.h>

/**
 * print_name - Prints a given name using the provided function pointer.
 * @name: Pointer to a character array representing the name.
 * @f: Function pointer to a function that can print the name.
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

