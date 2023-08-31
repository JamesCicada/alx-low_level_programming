#include <stdio.h>
#include "main.h"
/**
 * print_binary - Prints the binary of a number
 * @n: the number to be printed as binary
 *
 * Return: Always 0
 */

void print_binary(unsigned long int n)
{
	unsigned long int m = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int starts = 0;

	while (m > 0)
	{
		if (n & m)
		{
			putchar('1');
		}
		else if (starts)
		{
			putchar('0');
		}
		m >>= 1;
	}

	if (!starts)
	{
		putchar('0')
	}
}
