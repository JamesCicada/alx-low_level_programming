#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the natural square root of n, or -1 if n does not have a
 * natural square root
 */
int _sqrt_recursion(int n)
{
    if (n < 0)
        return (-1);
    if (n == 0 || n == 1)
        return (n);
    return (find_sqrt(n, 1, n));
}

/**
 * find_sqrt - recursively finds the natural square root of a number
 * within a range
 * @n: the number to find the square root of
 * @min: the minimum possible square root
 * @max: the maximum possible square root
 *
 * Return: the natural square root of n, or -1 if n does not have a
 * natural square root within the range [min, max]
 */
int find_sqrt(int n, int min, int max)
{
    int mid;

    if (min > max)
        return (-1);
    mid = (min + max) / 2;
    if (mid * mid == n)
        return (mid);
    if (mid * mid < n)
        return (find_sqrt(n, mid + 1, max));
    return (find_sqrt(n, min, mid - 1));
}

