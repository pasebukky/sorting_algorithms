#include "sort.h"

#define UP 0
#define DOWN 1

/**
 * swap - a function that swaps two elements in an array
 * @a: The first element
 * @b: The second element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * bitonic_merge - a function that sorts a bitonic sequence
 *
 * @array: input array
 * @size: size of @array
 * @start: index of the first element in the seq to sort
 * @seq_size: size of the seq to sort
 * @direction: direction to sort in
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size,
		char direction)
{
	size_t i, mov = seq_size / 2;

	if (seq_size > 1)
	{
		for (i = start; i < start + mov; i++)
		{
			if ((direction == UP && array[i] > array[i + mov]) ||
			    (direction == DOWN && array[i] < array[i + mov]))
				swap(array + i, array + i + mov);
		}
		bitonic_merge(array, size, start, mov, direction);
		bitonic_merge(array, size, start + mov, mov, direction);
	}
}


/**
 * bitonic_seq - a function that converts array of integers
 * into a bitonic sequence
 * @array: input array
 * @size: size of @array
 * @start: index at which the block starts
 * @seq_size: size of block
 * @direction: direction of sorting
 */

void bitonic_seq(int *array, size_t size, size_t start,
		size_t seq_size, char direction)
{
	size_t cut = seq_size / 2;
	char *str = (direction == UP) ? "UP" : "DOWN";

	if (seq_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq_size, size, str);
		print_array(array + start, seq_size);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq_size, direction);

		printf("Result [%lu/%lu] (%s):\n", seq_size, size, str);
		print_array(array + start, seq_size);
	}
}


/**
 * bitonic_sort - a function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of @array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
