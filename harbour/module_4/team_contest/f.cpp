#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n, c;
    cin >> n >> c;
    vector<int> ar(n + 1), br(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> br[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 1e9));
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + ar[i];
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + ar[i]);
        dp[i][1] = dp[i - 1][0] + br[i] + c;
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + br[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << min(dp[i][0], dp[i][1]) << (i == n ? '\n' : ' ');
    }
}
