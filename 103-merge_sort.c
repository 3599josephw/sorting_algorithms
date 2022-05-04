#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *Arr, int start, int mid, int end) {
	// create a temp array
	int* temp = (int*)malloc((end - start + 1) * sizeof(int));
	//int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval 
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
	free(temp);
}

// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr

void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
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
