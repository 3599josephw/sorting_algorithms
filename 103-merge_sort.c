#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - merge sorts
 * @arr: the array
 * @start: start
 * @mid: middle
 * @end: end
 */
void merge(int *arr, int start, int mid, int end) {
	
	int* temp = (int*)malloc((end - start + 1) * sizeof(int));

	/* crawlers for both intervals and for temp */
	int i = start, j = mid+1, k = 0;

	/* traverse both arrays and in each iteration add smaller of both elements in temp */
	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = arr[j];
			k += 1; j += 1;
		}
	}

	/* add elements left in the first interval */
	
	while(i <= mid) {
		temp[k] = arr[i];
		k += 1; i += 1;
	}

	/* add elements left in the second interval */
	while(j <= end) {
		temp[k] = arr[j];
		k += 1; j += 1;
	}

	/* copy temp to original interval */
	for(i = start; i <= end; i += 1) {
		arr[i] = temp[i - start];
	}
	free(temp);
}

/* arr is an array of integer type */
/* start and end are the starting and ending index of current interval of arr */
/**
 * mergeSort - merge sorts
 * @arr: the array
 * @start: start
 * @end: end
 */
void mergeSort(int *arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}
/**
 * merge_sort - merge sorts
 * @array: the array
 * @size: the size of array
 */
void merge_sort(int *array, size_t size) {
	if (size < 2) {
		return;
	}
    mergeSort(array, 0, size - 1);
}
