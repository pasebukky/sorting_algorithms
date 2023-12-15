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
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: pointer to the array of integers
 * @size: the size of the array
 * Return: the sorted array
 *
 */

void selection_sort(int *array, size_t size)
{
size_t i, j, min;

/* Lopp through each element in the array */
for (i = 0; i < size; i++)
{
	min = i; /* Assume the current index is the minimum */

	/* Loop through the remaining unsorted elements of the array */
	for (j = (i + 1); j < size; j++)
	{
		/* If the element is smaller than current min, update min */
		if (array[j] < array[min])
		{
			min = j;
		}
	}
	/* If min is not the same as current index, swap and print the array */
	if (min != i)
	{
		swap(&array[i], &array[min]);
		print_array(array, size);
	}
}
}
