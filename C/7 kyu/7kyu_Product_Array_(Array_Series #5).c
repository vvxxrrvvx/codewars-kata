#include <stdlib.h>

long long *productArray(const int numbers[], unsigned count) {
    long long *product = malloc(count * sizeof(long long));

    long long totalProduct = 1;
    for (unsigned i = 0; i < count; i++) {
        totalProduct *= numbers[i];
    }
    for (unsigned i = 0; i < count; i++) {
        product[i] = totalProduct / numbers[i];
    }
    return product;
}