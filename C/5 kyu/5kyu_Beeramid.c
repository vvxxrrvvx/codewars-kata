#include <math.h>

int beeramid(double bonus, double price) {
    int cans = floor(bonus / price);  // Maximum number of cans that can be purchased
    int levels = 0;
    int count = 1;

    // Calculate the number of complete levels that can be built
    while (cans >= count) {
        cans -= count;
        levels++;
        count = pow(levels + 1, 2);  // Number of cans required for the next level
    }

    return levels;
}