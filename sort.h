#ifndef sorting_algo
#define sorting_algo

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/*print functions*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recur(int *arr, int low, int heigh, size_t size);
int partition(int *array, int low, int heigh,  size_t size);
void swap(int *n1, int *n2);
int partition_hoare(int *array, int low, int heigh,  size_t size);
void quick_sort_hoare(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_reqer(int *array, int *buff, int l, int r);
void merge(int *array, int *buff, int l, int m, int r);

#endif

