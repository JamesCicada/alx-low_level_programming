#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the string to find the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (_strlen(s + 1) + 1);
}

/**
 * _check_palindrome - Checks if a string is a palindrome.
 * @s: A pointer to the string to check.
 * @start: The starting index of the string.
 * @end: The ending index of the string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int _check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	
	if (s[start] != s[end])
		return (0);
	
	return (_check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - Determines if a string is a palindrome.
 * @s: A pointer to the string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);
	if (len == 0 || len == 1)
		return (1);
	
	return (_check_palindrome(s, 0, len - 1));
}
1
