#include "sort.h"

/**
 * selection_sort - A function that use selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int auxvalue = 0;
	size_t i = 0, j = 0, idx = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}
		if (idx != i)
		{
			auxvalue = array[i];
			array[i] = array[idx];
			array[idx] = auxvalue;
			print_array(array, size);
		}
	}
}
