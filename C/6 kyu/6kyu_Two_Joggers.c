#include <stdio.h>

typedef struct Laps_Pairing {
    int bob;
    int charles;
} laps;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

laps nbr_of_laps(int x, int y) {
    int lcm = (x * y) / gcd(x, y);
    laps result;
    result.bob = lcm / x; 
    result.charles = lcm / y; 
    return result;
}