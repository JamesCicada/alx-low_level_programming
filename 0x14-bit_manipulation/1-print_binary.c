#include <stdio.h>
#include "main.h"
/**
 * print_binary - Prints the binary of a number.
 * @n: the number to be printed as binary.
 *
 * Description: Prints the binary representation of a number.
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	_putchar((n & 1) + '0');
}
