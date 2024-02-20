#include "sort.h"

void swap(int *n1, int *n2);
/**
 * selection_sort - sort int array based on selection
 * @array: array of int
 * @size: size of array
 * Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, m_index;


	for (i = 0; i < size - 1; i++)
	{
		m_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[m_index] > array[j])
			{
				m_index = j;
			}
		}
		if (m_index != i)
		{
			swap(&array[i], &array[m_index]);
		}
		print_array(array, size);
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
