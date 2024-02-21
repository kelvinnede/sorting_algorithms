#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - merge the subarrays in ascending or descending order
 * @array: array to sort
 * @start: starting index of the subarray
 * @size: size of the subarray
 * @dir: direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	if (size > 1)
	{
		size_t k = size / 2;
		size_t i;

		printf("Merging [%lu/%lu] (%s):\n", size, size * 2,
				dir == 1 ? "UP" : "DOWN");
		print_array(array + start, size);

		for (i = start; i < start + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int tmp = array[i];

				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}

		bitonic_merge(array, start, k, dir);
		bitonic_merge(array, start + k, k, dir);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	size_t k;

	for (k = 2; k <= size; k *= 2)
	{
		size_t j;

		for (j = k / 2; j > 0; j /= 2)
		{
			size_t i;

			for (i = 0; i < size; i += k)
			{
				int dir = (i / k) % 2 == 0 ? 1 : 0;

				bitonic_merge(array, i, k, dir);
			}
		}
	}
}
