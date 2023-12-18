#include "sort.h"
#include <stdio.h>

/**
* shell_sort - Sorts an array of integers in ascending order
*              using the Shell sort algorithm with the Knuth sequence.
* @array: The array to be sorted.
* @size: Number of elements in the array.
*/
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	size_t gap = 1;
	size_t i, j;
	int temp;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);
		gap /= 3;
	}
}
