#include "main.h"

/**
 * factorial - calculates the factorial of a number
 * @n: the number whose factorial to calculate
 *
 * Return: the factorial of the number, -1 if n is less than 0
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else if (n == 1)
		return (1);
	else
		return (n * factorial(n - 1));
}

