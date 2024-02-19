# include "sort.h"

/**
*bubble_sort - sorting array of int
*@array: arrauyo f int
*@size: array size
*Return: Nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
		{
			break;
		}
	}
}
