#include <stdio.h>
#include "main.h"
/**
 * binary_to_uint - Converts a binaru number to an unsigned int.
 * @b: The binary number.
 *
 * Return: Converted number or 0 if the provided binary is invalid.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i;

	if (b == NULL)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		num = num  << 1;
		num += b[i] - '0';
	}
	return (num);
}
