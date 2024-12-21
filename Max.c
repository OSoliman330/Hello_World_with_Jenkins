#include <stddef.h>
#include "Max.h"

int getMax(int *array, int size, int *max_value) {
    if (array == NULL || max_value == NULL) {
        return -1; // Error: One or more pointers are null
    }

    *max_value = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > *max_value) {
            *max_value = array[i];
        }
    }

    return 0; // Success
}