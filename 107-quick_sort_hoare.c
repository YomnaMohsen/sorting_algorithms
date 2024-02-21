#include "sort.h"
/**
 * quick_sort_hoare - sort int array (Hoare)
 * @array: array of int
 * @size: size of array
 * Return: Nothing
*/
void quick_sort_hoare(int *array, size_t size)
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
		index = partition_hoare(array, low, heigh, size);
		quick_sort_recur(array, low, index, size);
		quick_sort_recur(array, index + 1, heigh, size);
	}
}
/**
 *partition_hoare - divides array into 2 parts
 *@array: int array
 * @low: int starting index
 * @heigh: int end index
 * @size: size of array
 * Return: int index of pivot
*/
int partition_hoare(int *array, int low, int heigh,  size_t size)
{
	int pivot = array[heigh];
	int i = low - 1, j = heigh + 1;

	while (1)
	{

		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);
		if (i > j)
		{
			return (j);
		}
		if (array[i] != array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
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
