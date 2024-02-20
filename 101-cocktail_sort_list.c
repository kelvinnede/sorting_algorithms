#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 *
 * Description: The function sorts a doubly linked list of integers
 *              in ascending order using the Cocktail shaker sort algorithm.
 *              It iterates through the list in both directions, swapping adjacent
 *              elements if they are in the wrong order. The process is repeated
 *              until no more swaps are needed.
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
