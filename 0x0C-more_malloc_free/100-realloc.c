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
	void *new_ptr;
	
	if (new_size == 0)
	{
		free(ptr);
		return NULL;
	}
	
	if (ptr == NULL)
	{
		return malloc(new_size);
	}
	if (new_size == old_size)
	{
		return ptr;
	}
	
	new_ptr = malloc(new_size);
	
	if (new_ptr != NULL)
	{
		unsigned int min_size = old_size < new_size ? old_size : new_size;
		memcpy(new_ptr, ptr, min_size);
		free(ptr);
	}
	
	return new_ptr;
}

