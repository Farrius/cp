#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

int fact[MX];

int sum (int a, int b) {
    int c = a + b;
    if (c >= MOD) c -= MOD;
    return c;
}

int mul (int a, int b) {
    return (a * 1LL * b) % MOD;
}

int power (int a, int k) {
    int res = 1;
    while (k) {
        if (k % 2) res = mul(res, a);
        a = mul(a, a);
        k /= 2;
    }
    return res;
}

int divv (int a, int b) {
    return mul(a, power(b, MOD - 2));
}

int ncr (int n, int k) {
    int cur = fact[n];
    cur = divv(cur, fact[n - k]);
    cur = divv(cur, fact[k]);
    return cur;
}


int main () {
    fact[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = mul(fact[i - 1], i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) p1 = sum(p1, ncr(n, i));
            else p0 = sum(p0, ncr(n, i));
        }
        int tot = sum(p0, p1);
        vector<vector<int>> dp(k + 1, vector<int>(2));
        dp[0][0] = 1;
        for (int i = 0; i < k; i++) {
            dp[i + 1][1] = sum(dp[i + 1][1], dp[i][1]);
            dp[i + 1][1] = sum(dp[i + 1][1], mul(dp[i][1], tot));

            dp[i + 1][0] = sum(dp[i + 1][0], mul(dp[i][0], p0));
            
            if (n % 2) dp[i + 1][0] = sum(dp[i + 1][0], dp[i][0]);
            else dp[i + 1][1] = sum(dp[i + 1][1], dp[i][0]);
        }
        cout << sum(dp[k][1], dp[k][0]) << '\n';
    }
}
