#include "sort.h"
#include <stdio.h>

/**
* quick_sort - Sorts an array of integers in ascending order using
* the Quick sort algorithm with Lomuto partition scheme
*
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
* quicksort_recursive - Recursive helper function for Quick sort
*
* @array: The array to be sorted
* @low: The low index of the partition
* @high: The high index of the partition
* @size: Number of elements in the array
*/
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick sort
*
* @array: The array to be sorted
* @low: The low index of the partition
* @high: The high index of the partition
* @size: Number of elements in the array
*
* Return: The index of the pivot element
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j, temp;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] < pivot)
		{
			++i;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
