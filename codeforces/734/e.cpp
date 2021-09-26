#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (ar[i] == j + 1));
            }
        }

        int sol = 1e9;
        for (int j = n; j >= 0; j--) {
            if (dp[n][j] >= k) {
                sol = n - j;
                break;
            }
        }
        if (sol == 1e9) sol = -1;
        cout << sol << '\n';
    }
}
