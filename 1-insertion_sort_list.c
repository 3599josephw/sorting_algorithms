#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head = NULL, *p;

	while (*list != NULL)
	{
		current = *list;
		*list = (*list)->next;
		if (head == NULL || current->n < head->n)
		{
			current->next = head;
			head = current;
			print_list(*list);
		}
		else
		{
			p = head;
			while (p != NULL)
			{
				if (p->next == NULL || current->n < p->next->n)
				{
					current->next = p->next;
					p->next = current;
					print_list(*list);
					break;
				}
				p = p->next;
			}
		}
	}
}
