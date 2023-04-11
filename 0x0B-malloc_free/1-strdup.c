#include "main.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory, which contains
 * a copy of the string given as a parameter.
 *
 * @str: The string to be duplicated.
 *
 * Return: If str is NULL or if insufficient memory was available - NULL.
 * Otherwise - a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	char *dup_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	
	while (str[len] != '\0')
		len++;
	
	dup_str = malloc((len + 1) * sizeof(char));
	
	if (dup_str == NULL)
		return (NULL);
	
	for (i = 0; i <= len; i++)
		dup_str[i] = str[i];
	
	return (dup_str);
}

