#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 *
 */

void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}



/**
 * hoare_partition - performs the Hoare partition scheme
 *
 * @array: array to be partitioned
 * @size: size of the array
 * @low: low index
 * @high: high index
 * Return: index of the pivot element
 *
 */

int hoare_partition(int *array, size_t size, int low, int high)
{
int pivot = high;
int i = low;
int j = high;

do {
	while (array[i] < array[pivot])
		i++;

	while (array[j] > array[pivot])
		j--;

	if (!(i <= j))
		break;

	if (i != j)
	{
		if (j == pivot)
			pivot = i;

		swap(&array[i], &array[j]);
		print_array(array, size);
	}

	i++;
	j--;
} while (1);

return (j);
}





/**
 * recursive_quick_sort - recursive function to perform quicksort
 *
 * @array: array to be sorted
 * @size: size of the array
 * @low: starting index
 * @high: ending index
 *
 */

void recursive_quick_sort(int *array, size_t size, int low, int high)
{
if (low < high)
{
	int pivot_index = hoare_partition(array, size, low, high);

	recursive_quick_sort(array, size, low, pivot_index);
	recursive_quick_sort(array, size, pivot_index + 1, high);
}
}






/**
 * quick_sort_hoare - sorts an array using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 */

void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
	return;

recursive_quick_sort(array, size, 0, size - 1);
}
