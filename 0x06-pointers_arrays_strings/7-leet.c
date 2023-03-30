#include "main.h"

/**
 * leet - encodes a string into 1337.
 * @s: string to encode.
 *
 * Return: pointer to the encoded string.
 */
char *leet(char *s)
{
	char *p = s;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";
	
	while (*s)
	{
		int i;
		for (i = 0; letters[i]; i++)
		{
			if (*s == letters[i])
			{
				*s = numbers[i];
				break;
			}
		}
		s++;
	}
	return (p);
}

