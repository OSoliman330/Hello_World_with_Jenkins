#include <stdio.h>
#include "Max.h"

void test_getMax_valid_array(void) {
    int array[10] = {10, 23, 45, 67, 89, 12, 34, 56, 78, 90};
    int max_value;
    int status = getMax(array, 10, &max_value);
    if (status == 0 && max_value == 90) {
        printf("test_getMax_valid_array passed\n");
    } else {
        printf("test_getMax_valid_array failed\n");
    }
}

void test_getMax_null_array(void) {
    int max_value;
    int status = getMax(NULL, 10, &max_value);
    if (status == -1) {
        printf("test_getMax_null_array passed\n");
    } else {
        printf("test_getMax_null_array failed\n");
    }
}

void test_getMax_null_max_value(void) {
    int array[10] = {10, 23, 45, 67, 89, 12, 34, 56, 78, 90};
    int status = getMax(array, 10, NULL);
    if (status == -1) {
        printf("test_getMax_null_max_value passed\n");
    } else {
        printf("test_getMax_null_max_value failed\n");
    }
}

void test_getMax_empty_array(void) {
    int array[1] = {0};
    int max_value;
    int status = getMax(array, 0, &max_value);
    if (status == 0) {
        printf("test_getMax_empty_array passed\n");
    } else {
        printf("test_getMax_empty_array failed\n");
    }
}

int main(void) {
    test_getMax_valid_array();
    test_getMax_null_array();
    test_getMax_null_max_value();
    test_getMax_empty_array();
    return 0;
}