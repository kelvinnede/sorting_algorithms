#include "sort.h"


/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - Partitions the array into two parts
 * @array: Pointer to the array to be partitioned
 * @low: Index of the lower bound of the partition
 * @high: Index of the upper bound of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = low;
	int pivot = array[high], auxvalue = 0;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				auxvalue = array[i];
				array[i] = array[j];
				array[j] = auxvalue;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		auxvalue = array[i + 1];
		array[i + 1] = array[high];
		array[high] = auxvalue;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - Recursively sorts the array using Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @low: Index of the lower bound of the partition
 * @high: Index of the upper bound of the partition
 * @size: Size of the array
 */
void quick_s(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_s(array, low, pivot - 1, size);
		quick_s(array, pivot + 1, high, size);
	}
}
