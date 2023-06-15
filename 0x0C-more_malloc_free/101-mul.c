#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * multiply - multiplies two positive numbers
 * @num1: first number as a string
 * @num2: second number as a string
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, k, carry = 0;
	int *result;
	
	while (num1[len1])
	{
		if (!_isdigit(num1[len1]))
		{
			printf("Error\n");
			exit(98);
		}
		
		len1++;
	}
	
	while (num2[len2])
	{
		if (!_isdigit(num2[len2]))
		{
			printf("Error\n");
			exit(98);
		}
		len2++;
	}
	
	result = malloc((len1 + len2) * sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			k = i + j + 1;
			result[k] += (num1[i] - '0') * (num2[j] - '0');
			carry = result[k] / 10;
			result[k] %= 10;
			result[k - 1] += carry;
		}
	}
	
	i = 0;

	while (i < len1 + len2 && result[i] == 0)
		i++;
	
	if (i == len1 + len2)
		putchar('0');
	else
	{
		while (i < len1 + len2)
			putchar(result[i++] + '0');
	}
	putchar('\n');
	
	free(result);
}

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return 98;
	}
	multiply(argv[1], argv[2]);
	
	return 0;
}

