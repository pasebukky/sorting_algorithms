#include "sort.h"

/**
* bubble_sort - a function that implements a bubble sort algorithm
*
* @array: a pointer to an array of integers
* @size: the size of the array
*/


void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool bubbled;

	if (array == NULL || size <= 1)
		return;

	/* an outer loop for passes/rounds of bubbling */
	for (i = 0; i < (size - 1); i++)
	{
		/* this var checks if there was any bubbling in a round */
		bubbled = false;

		/*
		 * an inner loop to compare each index with the next except
		 * bubbled elements, hence (size - 1 - i)
		 */
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				bubbled = true;
				print_array(array, size);
			}
		}
		/* check if array is already sorted */
		if (bubbled == false)
			break;
	}
}
