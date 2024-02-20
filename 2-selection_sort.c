#include "sort.h"

/**
 * selection_sort -	sorts an array of integers in ascending order
 *			using the selection sort algorithm.
 * @array:		array to be sorted.
 * @size:		size of the array.
 * Return:		nothing.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, ptr = 0;
	int temp = 0;

	for (i = 0; i < size; i++)
	{
		ptr = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[ptr])
				ptr = j;
		}
		if (ptr != i)
		{
			temp = array[i];
			array[i] = array[ptr];
			array[ptr] = temp;
			print_array(array, size);
		}
	}
}
