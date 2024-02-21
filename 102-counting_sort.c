#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *output = NULL;
	int max = array[0], i;

	for (i = 1; i < size; i++)
		max = (array[i] > max) ? array[i] : max;

	count = calloc(max + 1, sizeof(int));
	if (count == NULL)
		return;

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	printf("%d", count[0]);
	for (i = 1; i <= max; i++)
		printf(", %d", count[i]);
	printf("\n");

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
		output[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
