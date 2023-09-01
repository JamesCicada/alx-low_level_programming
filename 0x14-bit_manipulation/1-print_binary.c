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
	n > 1 ? print_binary(b >> 1) : _putchar((b & 1) + '0');
}
