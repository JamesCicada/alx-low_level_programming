#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number to add
 * @n2: second number to add
 * @r: buffer to store the result
 * @size_r: buffer size
 *
 * Return: pointer to the result, or 0 if it can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int max_len = (len1 > len2) ? len1 : len2;
	int carry = 0;
	int i, sum;
	
	if (max_len + 1 > size_r)
		return 0;
	
	r[max_len + 1] = '\0';
	
	for (i = 1; i <= max_len; ++i)
	{
		sum = carry;
		if (i <= len1)
			sum += n1[len1 - i] - '0';
		if (i <= len2)
			sum += n2[len2 - i] - '0';
		carry = (sum >= 10) ? 1 : 0;
		r[max_len + 1 - i] = (sum % 10) + '0';
	}
	
	if (carry)
	{
		if (max_len + 2 > size_r)
			return 0;
		r[0] = '1';
		return r;
	}
	return r + 1;
}

