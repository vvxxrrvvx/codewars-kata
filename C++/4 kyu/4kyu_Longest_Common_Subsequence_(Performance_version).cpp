#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string lcs(const string& x, const string& y)
{
    vector<vector<int>> dp(x.size() + 1, vector<int>(y.size() + 1, 0));
    
    for (int i = 1; i <= x.size(); i++) {
        for (int j = 1; j <= y.size(); j++) {
            if (x[i-1] == y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string lcs_str = "";
    int i = x.size();
    int j = y.size();
    
    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            lcs_str += x[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    reverse(lcs_str.begin(), lcs_str.end());
    return lcs_str;
}