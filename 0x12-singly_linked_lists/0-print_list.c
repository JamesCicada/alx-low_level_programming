#include <stdio.h>
#include "lists.h"

size_t print_list(const list_t *h)
{
	size_t count = 0;
	
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", (int)h->len, h->str);
		
		h = h->next;
		count++;
	}
	
	return count;
}

