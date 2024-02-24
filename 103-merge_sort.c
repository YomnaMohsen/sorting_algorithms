#include "sort.h"
/**
 * merge_sort - sort array of int
 * @array: array of int
 * @size: size of array
 * Return: Nothing
*/
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2 || !array)
	{
		return;
	}
	buff = malloc(size * sizeof(int));
	if (buff == NULL)
	{
		return;
	}
	merge_sort_reqer(array, buff, 0, size - 1);
	free(buff);
}

/**
 * merge_sort_reqer - sort array by merge sort (top -down)
 * @array: array of int
 * @buffer: tmp buffer to store sorted values
 * @l: first index in left subarr
 * @r: last index in right subarr
 * Return: Nothing
*/
void merge_sort_reqer(int *array, int *buffer, int l, int r)
{
	int mid;

	if (l < r)
	{
		mid = (l + r) / 2;
		/*check on mid so left subarr_size <= right subarr_size*/
		if ((l + r) % 2 == 0)
		{
			mid--;
		}
		merge_sort_reqer(array, buffer, l, mid);
		merge_sort_reqer(array, buffer, mid + 1, r);
		merge(array, buffer, l, mid, r);
	}
}
/**
 *  merge - merge sorted subarr into buffer
 * @array: array of int
 * @buffer: tmp buffer to store sorted values
 * @left: first index in left subarr
 * @mid: mid index of array
 * @right: last index in right subarr
 * Return: Nothing
*/
void merge(int *array, int *buffer, int left, int mid, int right)
{
	int i, j, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);
	for (i = left, j = mid + 1; i <= mid && j <= right; k++)
	{
		if (array[i] <= array[j])
		{
			buffer[k] = array[i++];
		}
		else
		{
			buffer[k] = array[j++];
		}
	}
	/*transfer rest of values*/
	while (i <= mid)
	{
		buffer[k++] = array[i++];
	}

	while (j <= right)
	{
		buffer[k++] = array[j++];
	}
	/*copying values into main arr*/
	for (i = left; i <= right; i++)
	{
		array[i] = buffer[i];
	}
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}
