#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a list.
 * @head: Pointer to the pointer to the head node.
 * @idx: Index where the new node should be inserted.
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i;

	if (head == NULL)
		return NULL;

	/* Create a new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return NULL;
	new_node->n = n;

	if (idx == 0)
	{
		/* Insert at the beginning */
		new_node->next = *head;
		*head = new_node;
		return new_node;
	}

	current = *head;

	/* Traverse the list to the position of insertion */
	for (i = 0; i < idx - 1; i++)
	{
		if (current == NULL)
		{
			/* Index out of range */
			free(new_node);
			return NULL;
		}
		current = current->next;
	}

	/* Insert the new node */
	new_node->next = current->next;
	current->next = new_node;

	return new_node;
}

