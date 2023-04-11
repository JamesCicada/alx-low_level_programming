#include "main.h"

/**
 * str_concat - Concatenates two strings.
 *
 * @s1: The first string to concatenate.
 * @s2: The second string to concatenate.
 *
 * Return: If memory allocation fails, NULL.
 *         Otherwise - a pointer to the concatenated string.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int len_s1 = 0, len_s2 = 0, i, j;
	
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;

	concat_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (concat_str == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		concat_str[i] = s1[i];
	for (j = 0; s2[j]; j++)
	{
		concat_str[i] = s2[j];
		i++;
	}
	concat_str[i] = '\0';

	return (concat_str);
}

