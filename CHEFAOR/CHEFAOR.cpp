#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int n, k; cin >> n >> k; ) {
        int range[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> range[i][i];
        }
        for (int d = 1; d < n; d++) {
            for (int i = 1; i + d <= n; i++) {
                range[i][i + d] = range[i][i + d - 1] | range[i + d][i + d];
            }
        }
        long long dp[k + 1][n + 1], argmin[k + 1][n + 1];
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
            argmin[k][j] = j;
        }
        for (int i = 1; i <= k; i++) {
            dp[i][i] = dp[i - 1][i - 1] + range[i][i];
            argmin[i - 1][i] = i;
        }
        for (int d = 1; d < n; d++) {
            for (int i = 1; i + d <= n && i <= k; i++) {
                dp[i][i + d] = 0;
                for (long long k = argmin[i - 1][i + d - 1]; k <= argmin[i][i + d]; k++) {
                    long long t = dp[i - 1][k - 1] + range[k][i + d];
                    if (t > dp[i][i + d]) {
                        dp[i][i + d] = t;
                        argmin[i - 1][i + d] = k;
                    }
                }
            }
        }
        cout << dp[k][n] << '\n';
    }
    return 0;
}
