#include <stdbool.h>
#include <stdlib.h>

bool is_prime(long long num) {
    if (num < 2) {
        return false;
    }
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

long long* gap(int g, long long m, long long n) {
    long long prev_prime = 0;
    for (long long num = m; num <= n; num++) {
        if (is_prime(num)) {
            if (prev_prime != 0 && num - prev_prime == g) {
                long long* result = malloc(2 * sizeof(long long));
                result[0] = prev_prime;
                result[1] = num;
                return result;
            }
            prev_prime = num;
        }
    }
    long long* result = malloc(2 * sizeof(long long));
    result[0] = 0;
    result[1] = 0;
    return result;
}