#include <vector>

using namespace std;
using l = unsigned long long;

l solution(int n)
{
    vector<vector<l>> dp(n + 1, vector<l>(10, 0));
    
    for (int digit = 1; digit <= 9; digit++) {
        dp[1][digit] = 1;
    }
    
    for (int length = 2; length <= n; length++) {
        for (int digit = 0; digit <= 9; digit++) {
            if (digit > 0)
                dp[length][digit] += dp[length - 1][digit - 1];
            if (digit < 9)
                dp[length][digit] += dp[length - 1][digit + 1];
            dp[length][digit] %= 1000000007;
        }
    }
    
    l total = 0;
    for (int digit = 0; digit <= 9; digit++) {
        total += dp[n][digit];
        total %= 1000000007;
    }    
    return total;
}