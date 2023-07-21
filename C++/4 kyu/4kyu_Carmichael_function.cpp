#include <cmath>

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

long long Carmichael(long long n)
{
    if (n < 1 || n > 1e10) {
        return 0;  
    }

    long long result = 1;
    long long p = 2;

    while (p * p <= n)
    {
        if (n % p == 0)  
        {
            long long w = 0;
            while (n % p == 0) {
                n /= p;
                w++;
            }

            if (p > 2) {
                result = lcm(result, std::pow(p, w - 1) * (p - 1));
            }
            else if (p == 2 && w < 3) {
                result = lcm(result, std::pow(p, w) / 2);
            }
            else {
                result = lcm(result, std::pow(p, w - 1) * (p - 1) / 2);
            }
        }

        p++;
    }

    if (n > 1) {
        if (n > 2) {
            result = lcm(result, n - 1);
        }
        else {
            result = lcm(result, 1);
        }
    }

    return result;
}