#include <inttypes.h>
#include <math.h>

typedef uint64_t u64;

u64 modpow(u64 base, u64 exponent, u64 modulo) {
    if (modulo == 1) {
        return 0;
    }

    u64 result = 1;
    base %= modulo;

    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulo;
        }

        exponent >>= 1;
        base = (base * base) % modulo;
    }

    return result;
}