#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursively sorts a partition of an array
 * using the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: The lower bound of the partition.
 * @high: The higher bound of the partition.
 * @size: Number of elements in the array.
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		recursive_quick_sort(array, low, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: The lower bound of the partition.
 * @high: The higher bound of the partition.
 * @size: Number of elements in the array.
 *
 * Return: The final position of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}
