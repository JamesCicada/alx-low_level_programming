#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * reverse_listint - Reverses a linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: Pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return *head;
}

