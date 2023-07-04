#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index of a linked list.
 * @head: Pointer to the head node of the list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		current = *head;
		*head = current->next;
		free(current);
		return (1);
	}

	prev = *head;
	current = prev->next;

	for (i = 1; current != NULL; i++)
	{
		if (i == index)
		{
			prev->next = current->next;
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}

	return (-1);
}

