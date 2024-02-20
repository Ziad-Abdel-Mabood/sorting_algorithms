#include "sort.h"

void sort(int *array, size_t size, ssize_t low, ssize_t high);
size_t partition(int *array, size_t size, ssize_t low, ssize_t high);
void swap_array(int *array, size_t size, int *from, int *to);

/**
 * quick_sort -	sorts an array of integers in ascending
 *		order using the quick sort algorithm.
 * @array:	array to be sorted.
 * @size:	size of the array.
 * Return:	nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (size && array)
		sort(array, size, 0, size - 1);
}

/**
 * sort -	recursion call with more usable arguments.
 * @array:	array to be sorted.
 * @size:	size of the array.
 * @high:	high end index of the array or partition.
 * @low:	low end index of the array or partition.
 * Return:	nothing.
 */
void sort(int *array, size_t size, ssize_t low, ssize_t high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);

		/* recursion: on two partitions of the array */
		sort(array, size, low, pivot_index - 1);
		sort(array, size, pivot_index + 1, high);
	}
}

/**
 * partition -	separates an array into two partitions; larger
 *		and smaller than pivot.
 * @array:	array to be partitioned.
 * @size:	size of the array.
 * @low:	starting index of the partition.
 * @high:	ending index of the partition.
 * Return:	index of the pivot after it's put in its place.
 */
size_t partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int *pivot = array + high;
	int i = low - 1;
	int j;

	/* iterate over the array */
	for (j = low; j < high; j++)
	{
		/* if smaller than pivot; go to the beginning */
		if (array[j] <= *pivot)
		{
			i++;
			swap_array(array, size, array + i, array + j);
		}
	}
	/* swap pivot to its correct place */
	swap_array(array, size, array + i + 1, pivot);
	/* return the pivot index */
	return (i + 1);
}

/**
 * swap_array -	swaps two elements of an int array.
 * @array:	array to be sorted and printed.
 * @size:	size of the array.
 * @from:	first element pointer.
 * @to:		second element pointer.
 * Return:	nothing.
 */
void swap_array(int *array, size_t size, int *from, int *to)
{
	int temp;

	if (*from != *to)
	{
		temp = *from;
		*from = *to;
		*to = temp;
		print_array(array, size);
	}
}
