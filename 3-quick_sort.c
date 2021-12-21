#include "sort.h"
/**
 * quick_sort - quick sort algorithm
 * @array: array given to us
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}
int partition (int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1), j, tmpi, tmpj, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmpi = arr[i];
			tmpj = arr[j];
			swap(&arr[i], &arr[j]);
			if (tmpi != arr[i] && tmpj != arr[j])
				print_array(arr, size);
		}
	}
	tmp = arr[i + 1];
	swap(&arr[i + 1], &arr[high]);
	if (arr[i + 1] != tmp)
		print_array(arr, size);
	return (i + 1);
}
void quickSort(int arr[], int low, int high, size_t size)
{
	int pi;
	if (low < high)
	{
		pi = partition(arr, low, high, size);
		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}
