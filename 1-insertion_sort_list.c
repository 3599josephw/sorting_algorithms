#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *swap;

	if (*list != NULL)
	{
		current = *list;
		tmp = current->next;
		if (tmp == NULL)
			return;
		while (tmp != NULL)
		{
			if (current->n > tmp->n)
			{
				while (current->prev != NULL && current->n > tmp->n)
				{
					if (current->prev->n < tmp->n)
						break;
					current = current->prev;
				}
				/* possible not hitting while loop */
				swap = current;
				current = tmp;
				tmp = swap;
				tmp = current->next;
				print_list(*list);
			}
			if (current->next != NULL)
				current = current->next;
			tmp = current->next;
			/* y u no work? */
		}
	}
}
