#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - mergesort
 * @arr: the array
 * @l: left
 * @m: m!
 * @r: right
 */
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/**
 * mergeSort - mergesorts
 * @arr: the array
 * @l: left
 * @r: right
 */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/**
 * merge_sort - merge sorts
 * @array: the array
 * @size: the size of array
 */
void merge_sort(int *array, size_t size) {
    mergeSort(array, 0, size - 1);
}
