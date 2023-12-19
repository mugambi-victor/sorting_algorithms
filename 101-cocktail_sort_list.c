#include "sort.h"
#include <stdio.h>

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;

	if (a->next)
		a->next->prev = a;
	else
		(*list)->prev = a;

	b->prev = b;
}


/**
* cocktail_sort_list - Sorts a doubly linked list in ascending order
*                     using the Cocktail Shaker sort algorithm.
* @list: Double pointer to the head of the list.
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;

	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
