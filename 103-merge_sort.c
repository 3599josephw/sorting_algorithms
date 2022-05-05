#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - merge sorts
 * @arr: the array
 * @start: start
 * @mid: middle
 * @end: end
 * @temp: temp array
 */
void merge(int *arr, int start, int mid, int end, int *temp)
{
	int i = start, j = mid + 1, k = 0;

	/* traverse arrays, each iteration add smaller of both elements in temp */
	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			k += 1; i += 1;
		}
		else
		{
			temp[k] = arr[j];
			k += 1;
			j += 1;
		}
	}
	/* add elements left in the first interval */
	while (i <= mid)
	{
		temp[k] = arr[i];
		k += 1;
		i += 1;
	}
	/* add elements left in the second interval */
	while (j <= end)
	{
		temp[k] = arr[j];
		k += 1;
		j += 1;
	}
	/* copy temp to original interval */
	for (i = start; i <= end; i += 1)
	{
		arr[i] = temp[i - start];
	}
}

/**
 * mergeSort - merge sorts
 * @arr: the array
 * @start: start
 * @end: end
 * @temp: temp array
 */
void mergeSort(int *arr, int start, int end, int *temp) {

	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid, temp);
		mergeSort(arr, mid + 1, end, temp);
		merge(arr, start, mid, end, temp);
	}
}
/**
 * merge_sort - merge sorts
 * @array: the array
 * @size: the size of array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
	{
		return;
	}
	temp = (int *)malloc((size) * sizeof(int));
	mergeSort(array, 0, size - 1, temp);
	free(temp);
}
