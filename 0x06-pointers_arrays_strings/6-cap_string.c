#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to be modified.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
	int i, j;
	char separators[] = " \t\n,;.!?\"(){}";
	for (i = 0; str[i] != '\0'; i++)
	{
		/* Capitalize if the first letter of the string */
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		/* Capitalize if the current character is a separator */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i] == separators[j])
			{
				/* Capitalize the next letter if it's lowercase */
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
					str[i + 1] -= 32;
				break;
			}
		}
	}
	return (str);
}

