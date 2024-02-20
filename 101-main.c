#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @prev: Double pointer to the previous node
 * @next: Double pointer to the next node
 *
 * Description: This function swaps two nodes in a doubly linked list.
 */
void swap_nodes(listint_t **list, listint_t **prev, listint_t **next)
{
	listint_t *tmp_prev, *tmp_next;

	tmp_prev = (*prev)->prev;
	tmp_next = (*next)->next;

	if (tmp_prev)
		tmp_prev->next = (*next);
	else
		*list = (*next);

	if (tmp_next)
		tmp_next->prev = (*prev);

	(*prev)->next = tmp_next;
	(*prev)->prev = (*next);
	(*next)->next = (*prev);
	(*next)->prev = tmp_prev;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker sort
 * @list: Double pointer to the head of the list
 *
 * Description: This function sorts a doubly linked list of integers
 *              in ascending order using the Cocktail Shaker sort algorithm.
 *              It prints the list after each time two elements are swapped.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL;
	int swapped;

	if (!list || !(*list) || !((*list)->next))
		return;

	do {
		swapped = 0;
		start = (*list);
		while (start->next != end) {
			if (start->n > start->next->n) {
				swap_nodes(list, &start, &(start->next));
				swapped = 1;
				print_list((*list));
			} else {
				start = start->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		end = start;
		while (start->prev != NULL) {
			if (start->n < start->prev->n) {
				swap_nodes(list, &(start->prev), &start);
				swapped = 1;
				print_list((*list));
			} else {
				start = start->prev;
			}
		}
	} while (swapped);
}
