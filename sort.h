#ifndef SORT_H
#define SORT_H
#include <string.h>
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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quickSort(int arr[], int low, int high, size_t size);
int partition(int arr[], int low, int high, size_t size);
void swap(int *a, int *b);
void merge_sort(int *array, size_t size);
void mergeSort(int *arr, int start, int end, int *temp);
void merge(int *Arr, int start, int mid, int end, int *temp);
void heap_sort(int *array, size_t size);
void heapify(int array[], int size, int i, size_t max_size);
void radix_sort(int *a, size_t size);
void countingSort(int array[], int size, int place);
int getMax(int *array, int n);
#endif
