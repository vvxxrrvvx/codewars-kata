#include <iostream>
#include <numeric>
using namespace std;

bool are_coprime(unsigned int a, unsigned int b) {
    return gcd(a, b) == 1;
}