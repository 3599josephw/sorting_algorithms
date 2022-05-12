#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @array: the array
 * @size: size of array
 * @i: iterator
 * @max_size: max size of array for printing
 */
void heapify(int array[], int size, int i, size_t max_size)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    int tmp;

    if (l < size && array[l] > array[largest])
        largest = l;

    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        tmp = array[i];
        array[i] = array[largest];
        array[largest] = tmp;
        print_array(array, max_size);

        heapify(array, size, largest, max_size);
    }
}

/**
* @array: the array
* @size: size of array
*/
void heap_sort(int *array, size_t size)
{
    int tmp, max_size = size;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i, max_size);
    }

    for (int i = size - 1; i >= 0; i--) {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        if (i > 0) {
            print_array(array, max_size);
        }
        heapify(array, i, 0, max_size);
    }
}