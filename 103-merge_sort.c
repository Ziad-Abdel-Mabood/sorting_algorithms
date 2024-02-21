#include "sort.h"
#include <stdio.h>

void merge_compare(int *array, size_t start, size_t stop, int *new);
void merge_sort_td(int *array, size_t start, size_t stop, int *new);

/**
 * merge_sort -	sorts by merge sort algorithm.
 * @array:	the integer array to sort.
 * @size:	the size of the array.
 * Return:	nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;

	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;

	for (i = 0; i < size; i++)
		new[i] = array[i];
	merge_sort_td(new, 0, size, array);
	free(new);
}

/**
 * merge_sort_td -	sorts top down recursively.
 * @array:		array to be sorted.
 * @start:		beginning index.
 * @stop:		last index.
 * @new:		resulting array.
 * Return:		nothing.
 */
void merge_sort_td(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
		return;

	merge_sort_td(new, start, mid, array);
	merge_sort_td(new, mid, stop, array);
	merge_compare(array, start, stop, new);
}

/**
 * merge_compare -	compares merging.
 * @array:		array to be sorted.
 * @start:		beginning index.
 * @stop:		last index.
 * @new:		result array.
 * Return:		nothing.
 */
void merge_compare(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start;
	size_t j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);

	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
			new[k] = array[i++];
		else
			new[k] = array[j++];

	printf("[Done]: ");
	print_array(new + start, stop - start);
}
