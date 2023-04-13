#include "main.h"

/**
 * _calloc - Allocates memory for an array of elements
 *            and initializes it with zeros.
 *
 * @nmemb: The number of elements to allocate memory for.
 * @size: The size of each element.
 *
 * Return: If memory allocation fails, return NULL.
 *         Otherwise, return a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem = malloc(nmemb * size);

	if (mem == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		mem[i] = 0;

	return ((void *)mem);
}

