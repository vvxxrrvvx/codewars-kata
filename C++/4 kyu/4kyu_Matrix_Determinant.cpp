#include <vector>

using namespace std;

long long determinant(vector<vector<long long>> m) {
    int n = m.size();
    if (n == 1) {
        return m[0][0];
    } else if (n == 2) {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    } else {
        long long det = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<long long>> temp(n - 1, vector<long long>(n - 1));
            for (int j = 1; j < n; j++) {
                int l = 0;
                for (int k = 0; k < n; k++) {
                    if (k != i) {
                        temp[j - 1][l] = m[j][k];
                        l++;
                    }
                }
            }
            det += ((i % 2 == 0) ? 1 : -1) * m[0][i] * determinant(temp);
        }
        return det;
    }
}