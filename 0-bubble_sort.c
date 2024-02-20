#include "sort.h"

/**
 * bubble_sort - sort array using bubble sort
 * @array: the array to be sorted
 * @size: the lenght of the array;
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t temp, i, j, sorted_data = 1,  swaptemp;

	if (!array || size < 1)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		swaptemp = 0;

		for (j = 0; j < size - sorted_data; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swaptemp = 1;
			}
		}


		/* if no element were swapped, the array is sorted */
		if (!swaptemp)
		{
			break;
		}
		sorted_data++;
	}
}
