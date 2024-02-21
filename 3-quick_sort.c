#include "sort.h"
/**
 * quick_sort - sort int array
 * @array: array of int
 * @size: size of array
 * Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
	{
		return;
	}
	quick_sort_recur(array, 0, size - 1, size);
}
/**
 * quick_sort_recur - sort int array recuersively
 * @array: int array
 * @low: first element index
 * @heigh: last element index
 * @size: size of array
*/
void quick_sort_recur(int *array, int low, int heigh, size_t size)
{
	int index;

	if (low < heigh)
	{
		index = partition(array, low, heigh, size);
		quick_sort_recur(array, low, index - 1, size);
		quick_sort_recur(array, index + 1, heigh, size);
	}
}
/**
 *partition - divides array into 2 parts
 *@array: int array
 * @low: int starting index
 * @heigh: int end index
 * @size: size of array
 * Return: int index of pivot
*/
int partition(int *array, int low, int heigh,  size_t size)
{
	int i = low, j;
	int pivot = array[heigh];

	for (j = low; j < heigh; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != j)
	{
		swap(&array[i], &array[heigh]);
		print_array(array, size);
	}
	return (i);
}
/**
 * swap - swap two int
 * @n1: pointer to first int
 * @n2: pointer to second int
 * Return: Nothing
*/
void swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
