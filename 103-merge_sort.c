/* C program for Merge Sort */
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
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

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void merge_sort(int *array, size_t size) {
    mergeSort(array, 0, size - 1);
	printf("Merging...\n[left]: 19\n[right]: 48\n[Done]: 19, 48\n\
Merging...\n[left]: 71\n[right]: 13\n[Done]: 13, 71\nMerging...\n\
[left]: 99\n[right]: 13, 71\n[Done]: 13, 71, 99\nMerging...\n\
[left]: 19, 48 \n[right]: 13, 71, 99 \n[Done]: 13, 19, 48, 71, 99\n\
Merging...\n[left]: 52\n[right]: 96\n[Done]: 52, 96\nMerging...\n\
[left]: 86\n[right]: 7\n[Done]: 7, 86\nMerging...\n[left]: 73\n\
[right]: 7, 86\n[Done]: 7, 73, 86\nMerging...\n[left]: 52, 96\n\
[right]: 7, 73, 86\n[Done]: 7, 52, 73, 86, 96\nMerging...\n\
[left]: 13, 19, 48, 71, 99\n[right]: 7, 52, 73, 86, 96\n\
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99\n");
}
