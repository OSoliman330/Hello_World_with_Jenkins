#include <stdio.h>
#include <stdlib.h>
#include "Max.h"

#define ARRAY_SIZE 10

int main(void) 
{
    int max_value;
    int status;

    // Fill the array with fixed values
    int array[ARRAY_SIZE] = {10, 23, 45, 67, 89, 12, 34, 56, 78, 90};

    // Call getMax to find the maximum value in the array
    status = getMax(array, ARRAY_SIZE, &max_value);

    if (status == 0) {
        printf("The maximum value in the array is: %d\n", max_value);
    } else {
        printf("Error: One or more pointers are null.\n");
    }

    return 0;
}