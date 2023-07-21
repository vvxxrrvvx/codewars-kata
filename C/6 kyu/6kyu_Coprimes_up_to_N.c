#include <stddef.h>
#include <stdlib.h>

unsigned gcd(unsigned a, unsigned b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unsigned *coprimes(unsigned n, unsigned *output, size_t *length) {
    unsigned count = 0;
    for (unsigned k = 1; k < n; k++) {
        if (gcd(n, k) == 1) {
            output[count] = k;
            count++;
        }
    }
    *length = count;
    return output;
}