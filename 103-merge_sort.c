#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	/* Allocate space for temporary array */
	int *temp = malloc(sizeof(int) * size);

	if (temp == NULL)
		return;

	/* Recursively split and merge */
	split_merge(array, 0, size, temp);

	/* Free temporary array */
	free(temp);
}

/**
 * split_merge - Splits and merges the sub-arrays
 * @array: The array to sort
 * @start: The start index of the sub-array
 * @end: The end index of the sub-array
 * @temp: The temporary array for merging
 */
void split_merge(int *array, size_t start, size_t end, int *temp)
{
	if (end - start < 2)
		return;

	size_t mid = (start + end) / 2;

	split_merge(array, start, mid, temp);
	split_merge(array, mid, end, temp);
	merge(array, start, mid, end, temp);
}

/**
 * merge - Merges the sub-arrays
 * @array: The array to sort
 * @start: The start index of the left sub-array
 * @mid: The end index of the left sub-array and start
 * @end: The end index of the right sub-array
 * @temp: The temporary array for merging
 */
void merge(int *array, size_t start, size_t mid, size_t end, int *temp)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	size_t i = start, j = mid, k = 0;

	while (i < mid && j < end)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < end)
		temp[k++] = array[j++];

	for (i = start, k = 0; i < end; i++, k++)
		array[i] = temp[k];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
