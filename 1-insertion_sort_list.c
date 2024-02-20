#include "sort.h"
/**
 * insertion_sort_list - sort doubly linkedlist
 * @list: pointer to head of linkedlist
 * Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	curr = (*list)->next;/*key*/
	while (curr)
	{
		next = curr->next;
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			tmp = curr->prev;/*b4 key*/
			tmp->next = curr->next;
			curr->prev = tmp->prev;
			if (curr->next != NULL)
			{
				curr->next->prev = tmp;
			}
			curr->next = tmp;
			if (tmp->prev != NULL)
			{
				tmp->prev->next = curr;
			}
			else
			{
				*list = curr;
			}
			tmp->prev = curr;
			print_list(*list);
		}
		curr = next;
	}
}
