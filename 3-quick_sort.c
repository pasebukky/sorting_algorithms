#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @a: First integer
 * @b: Second integer
 *
 */

void swap(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}







/**
 * lomuto - partitions arrays using pivot method
 *
 * @array: the array of elements
 * @low: start of the partition index
 * @high: end of the partition index
 * @size: size of the array
 *
 * Return: Index of the pivot
 *
 */

size_t lomuto(int *array, size_t low, size_t high, size_t size)
{
int pivot;
size_t i, j;

pivot = array[high]; /* Use last element as pivot */
i = low; /* Initialize i to index of smaller element */

/* Loop through the partition */
for (j = low; j <= high - 1; j++)
{
	/* Check if the current element is <= to the pivot */
	if (array[j] <= pivot)
	{
		if (i != j) /* Swap elements if they are different */
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		i++; /* Increment along the array */
	}
}
/* Swap pivot element into the correct position */
swap(&array[i], &array[high]);
print_array(array, size);
return (i); /* Return index of the pivot */
}







/**
 * recursive_sort - sorts recursively
 *
 * @array: the array of elements
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 *
 */

void recursive_sort(int *array, size_t low, size_t high, size_t size)
{
size_t index; /* Partitioned index */

if (low < high)
{
	/* Get index using lomuto */
	index = lomuto(array, low, high, size);

	/* Recursively sort left array */
	if (index != 0)
	{
		recursive_sort(array, low, index - 1, size);
	}
	/* Recursively sort right array */
	recursive_sort(array, index + 1, high, size);
}
}







/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: the array of elements
 * @size: size of the array
 * Return : 1 if failed
 */

void quick_sort(int *array, size_t size)
{
/* Check if array is NULL or has only one elemet */
if (array == NULL || size <= 1)
	return;
/* Use recursive_sort to perform quick sort */
recursive_sort(array, 0, (size - 1), size);
}
