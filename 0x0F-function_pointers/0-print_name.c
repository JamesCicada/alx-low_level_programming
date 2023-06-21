#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - print name
 * @name: the name to be printed
 * @f: pointer to function
 * Return: nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (f && name)
		f(name);
}
