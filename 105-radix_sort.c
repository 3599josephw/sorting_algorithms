#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * max_int - gets the max int
 * @array: the array
 * @size: size of the array
 * Return: the max value
 */
int max_int(int *array, int size) {
    int tmp = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (array[i]> tmp){
            tmp = array[i];
        }
    }
    return tmp;
}

/**
 * countSort - helper functions
 * @array: the array
 * @size: size of array
 * @exp: the exp
 * @count: the count
 * @result: the result
 */
void countSort (int *array, int size, int exp, int *count, int *result) {
    int lsd;
    int i, index;

    for (i = 0; i < size; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        lsd = (array[i] / exp) % 10;
        count[lsd]++;
    }

    for (i = 1; i < size; i++) {
        count[i] += count[i-1];
    }

    for (i = size - 1; i >= 0; i--) {
        lsd = (array[i] / exp) % 10;
        index = count[lsd] - 1;
        result[index] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++) {
        array[i] = result[i];
    }
}

/**
 * radix_sort - sorts the array
 * @array: the array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size){

    int m = max_int(array, size);
    int i = 0;

    int *count = malloc(size * sizeof(int));
    int *result = malloc(sizeof(int) * size);

    for (i = 1; m / i > 0; i = i * 10) {
        countSort(array, size, i, count, result);
        print_array(array, size);
    }

    free(count);
    free(result);
}