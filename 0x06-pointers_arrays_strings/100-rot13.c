#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 * @s: the string to encode.
 *
 * Return: a pointer to the encoded string.
 */
char *rot13(char *s)
{
	int i, j;
	char *rot13 = s;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13_alphabet[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; alphabet[j] != '\0'; j++)
		{
			if (s[i] == alphabet[j])
			{
				rot13[i] = rot13_alphabet[j];
				break;
			}
		}
	}
	return rot13;
}

