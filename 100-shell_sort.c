#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with Knuth sequence
 * @array: Array to sort
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    /* Calculate initial gap using Knuth sequence */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Loop over gaps from the largest to 1 */
    for (; gap > 0; gap /= 3)
    {
        /* Perform insertion sort for current gap */
        for (i = gap; i < size; i++)
        {
            /* Insert array[i] into the sorted sequence array[0..i-gap-1] */
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        /* Print the array after each decrease in gap */
        print_array(array, size);
    }
}
