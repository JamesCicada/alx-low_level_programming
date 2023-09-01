#include <stdio.h>
#include "main.h"
/**
 * get_bit - Calculates the value of a bit at a given index
 * @n: The bit to be calculated
 * @index: The index of the bit
 *
 * Return: The value of a n at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned int long) * 8)
		return (-1);

	return((n >> index) & 1);
}
