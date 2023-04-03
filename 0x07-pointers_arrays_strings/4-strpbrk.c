#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the set of bytes to search for
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 *         or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *match;
	while (*s != '\0')
	{
		match = accept;
		while (*match != '\0')
		{
			if (*s == *match)
				return s;
			match++;
		}
		s++;
	}
	return NULL;
}


