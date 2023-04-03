#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: the string to search in
 * @needle: the substring to search for
 *
 * Return: a pointer to the beginning of the located substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;
	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;
		while (*n == *haystack && *n != '\0' && *haystack != '\0')
		{
			n++;
			haystack++;
		}
		if (*n == '\0')
			return h;
		haystack = h + 1;
	}
	return NULL;
}

