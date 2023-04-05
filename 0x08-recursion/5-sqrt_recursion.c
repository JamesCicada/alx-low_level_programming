#include "main.h"
/**
 * _sqrt_recursion_helper - recursive helper function to find the square root of a number
 * @n: the number to find the square root of
 * @root: the current root value
 * @prev: the previous root value
 *
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion_helper(int n, int root, int prev)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	if (root * root == n)
		return (root);
	if (root == prev)
		return (-1);
	
	return (_sqrt_recursion_helper(n, (root + n / root) / 2, root));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_recursion_helper(n, n / 2, 0));
}

