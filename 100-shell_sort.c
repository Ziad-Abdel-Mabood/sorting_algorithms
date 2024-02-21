#include "sort.h"

size_t get_max_gap(size_t size);

/**
 * shell_sort -	sorts an array of integers in ascending order
 *		using the Shell sort algorithm, using the Knuth sequence.
 * @array:	array to be sorted.
 * @size:	size of the array.
 * Return:	nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
		return;

	for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

/**
 * get_max_gap -	calculates largest Knuth sequence gap.
 * @size:		size of the array.
 * Return:		gap size.
 */
size_t get_max_gap(size_t size)
{
	size_t i, gap;

	i = 1;
	while (i < size)
		i = i * 3 + 1;
	gap = (i - 1) / 3;
	return (gap);
}
