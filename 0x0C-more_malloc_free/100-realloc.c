#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * _realloc - reallocates memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to new memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr, *temp;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		free(ptr);
		return (newptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
	temp = ptr;
	for (i = 0; i < old_size; i++)
		newptr[i] = temp[i];

	free(ptr);
	return (newptr);
}
