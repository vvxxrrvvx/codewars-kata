#include <stdlib.h>

typedef struct _array_minmax_t {
    int *array;
    unsigned int length;
    int min;
    int max;
} array_minmax_t;

array_minmax_t *array_minmax_create(unsigned int length, int *input_array) {
    array_minmax_t *new_array = malloc(sizeof(array_minmax_t));
    new_array->array = malloc(length * sizeof(int));
    new_array->length = length;
    new_array->min = input_array[0];
    new_array->max = input_array[0];

    for (unsigned int i = 0; i < length; i++) {
        new_array->array[i] = input_array[i];
        if (input_array[i] < new_array->min) {
            new_array->min = input_array[i];
        }
        if (input_array[i] > new_array->max) {
            new_array->max = input_array[i];
        }
    }

    return new_array;
}

void array_minmax_add(array_minmax_t *array, int number) {
    if (number < array->min) {
        array->min = number;
    }
    if (number > array->max) {
        array->max = number;
    }
}

int array_minmax_get_min(array_minmax_t *array) {
    return array->min;
}

int array_minmax_get_max(array_minmax_t *array) {
    return array->max;
}

void array_minmax_destroy(array_minmax_t *array) {
    free(array->array);
    free(array);
}