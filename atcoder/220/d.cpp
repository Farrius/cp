#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;

int sum (int a, int b) {
    int c = a + b;
    if (c > MOD) c -= MOD;
    return c;
}

int main () {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    vector<vector<int>> dp(n, vector<int>(10));
    dp[0][ar[0]] = 1;
    for (int i = 1; i < n; ++i) {
        int y = ar[i];
        for (int x = 0; x < 10; ++x) {
            dp[i][(x * y) % 10] = sum(dp[i][(x * y) % 10], dp[i - 1][x]);
            dp[i][(x + y) % 10] = sum(dp[i][(x + y) % 10], dp[i - 1][x]);
        }
    }

    for (int x = 0; x < 10; ++x) {
        cout << dp[n - 1][x] << '\n';
    }
}
