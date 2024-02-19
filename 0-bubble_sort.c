#include "sort.h"

/**
 * bubble_sort -	sorts an array using bubble sort algorithm.
 * @array:		the array to be sorted.
 * @size:		size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int count;
	int temp = 0;
	unsigned int k = 0;
	unsigned int i = 0;

	for(; k < size; k++)
	{
		i = 0;
		count = 0;
		for(; i < size - 1; i++)
		{
			/* if unsorted then swap */
			if(array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				count++;
				print_array(array, size);
			}
		}
		if(count == 0)
			return;
	}
}


