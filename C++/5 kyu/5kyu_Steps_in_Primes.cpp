#include <vector>
#include <utility>
#include <cmath>

class StepInPrimes
{
public:
    static std::pair<long long, long long> step(int g, long long m, long long n)
    {
        for (long long i = m; i <= n - g; ++i)
        {
            if (isPrime(i) && isPrime(i + g))
            {
                return {i, i + g};
            }
        }

        return {0, 0};
    }

private:
    static bool isPrime(long long num)
    {
        if (num < 2)
            return false;

        for (long long i = 2; i <= std::sqrt(num); ++i)
        {
            if (num % i == 0)
                return false;
        }

        return true;
    }
};