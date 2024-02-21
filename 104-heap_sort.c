#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

void siftdown(int *array, size_t size, size_t start, size_t end);
void heapify(int *array, size_t size);
void swap_array(int *array, size_t size, int *from, int *to);

/**
 * heap_sort -	sorts an array using heap sort algorithm (siftdown)
 * @array:	array to be sorted.
 * @size:	size of the array to be sorted.
 * Return:	nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap_array(array, size, array + end, array);
		end--;
		siftdown(array, size, 0, end);
	}
}

/**
 * siftdown -	siftdown and sorting the maximum int.
 * @array:	array to be sorted.
 * @start:	start of array.
 * @end:	end of array.
 * @size:	size of array.
 * Return:	northing.
 */
void siftdown(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t _swap, child;

	while (leftchild(root) <= end)
	{
		child = leftchild(root);
		_swap = root;
		if (array[_swap] < array[child])
			_swap = child;
		if (child + 1 <= end && array[_swap] < array[child + 1])
			_swap = child + 1;
		if (_swap == root)
			return;
		swap_array(array, size, array + root, array + _swap);
		root = _swap;
	}
}

/**
 * heapify -	makes heap in place.
 * @array:	array to be sorted.
 * @size:	size of the array.
 * Return:	nothing.
 */
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	while (start >= 0)
	{
		siftdown(array, size, start, size - 1);
		start--;
	}
}

/**
 * swap_array -	swaps two elements in an array.
 * @array:	array to be sorted.
 * @size:	size of the array.
 * @from:	first swap element.
 * @to:		second element to swap.
 * Return:	nothing.
 */
void swap_array(int *array, size_t size, int *from, int *to)
{
	if (*from != *to)
	{
		*from = *from + *to;
		*to = *from - *to;
		*from = *from - *to;
	}
	print_array((const int *)array, size);
}
