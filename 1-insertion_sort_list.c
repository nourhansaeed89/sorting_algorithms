#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			temp = current->next;
			if (temp)
				temp->prev = prev;
			prev->next = temp;

			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;

			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
