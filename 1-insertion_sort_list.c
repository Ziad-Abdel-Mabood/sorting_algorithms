#include "sort.h"

void swap_dbl_list(listint_t *node);


/**
 * insertion_sort_list -	sorts a doubly linked list of ints in an ascending
 *				order using the insertion sort algorithm.
 * @list:			list to be sorted.
 * Return:			nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr1;
	listint_t *ptr2;

	if (!list)
		return;
	ptr1 = (*list)->next;
	/* iterate over the list */
	while (ptr1)
	{
		ptr2 = ptr1;
		/**
		 * start from second node, if its data is less than the previous
		 * node; then swap(send it backwards) and check again.
		 */
		while (ptr2->prev && ptr2->prev->n > ptr2->n)
		{
			swap_dbl_list(ptr2);

			while ((*list)->prev)
				*list = (*list)->prev;
			print_list(*list);
		}
		ptr1 = ptr1->next;
	}
}

/**
 * swap_dbl_list -	swaps a node in a doubly linked list with its previous node.
 * @node:		node to be swapped.
 * Return:		nothing.
 */
void swap_dbl_list(listint_t *node)
{
	listint_t *temp;

	temp = node->prev;

	if (temp->prev)
	{
		node->prev = temp->prev;
		node->prev->next = node;
	}
	else	/* checking if we reached the start of the list */
		node->prev = NULL;

	temp->prev = node;

	if (node->next)
	{
		temp->next = node->next;
		node->next->prev = temp;
	}
	else	/* we reached the end of the list */
		temp->next = NULL;

	node->next = temp;
}
