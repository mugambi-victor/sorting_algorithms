#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked
 * list of integers in ascending order
 * using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion = current;
		current = current->next;

		while (insertion->prev != NULL && insertion->n < insertion->prev->n)
		{
			if (insertion->next != NULL)
				insertion->next->prev = insertion->prev;
			insertion->prev->next = insertion->next;
			insertion->next = insertion->prev;
			insertion->prev = insertion->prev->prev;
			insertion->next->prev = insertion;

			if (insertion->prev == NULL)
				*list = insertion;
			else
				insertion->prev->next = insertion;
			print_list(*list);
		}
	}
}
