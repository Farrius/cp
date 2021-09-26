#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int sum (int a, int b) {
    int c = a + b;
    if (c >= MOD) c -= MOD;
    return c;
}

int main () {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> dp(n + 2);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; ; j--) {
            dp[i + 2] = sum(dp[i + 2], dp[j + 1]);
            if (j == -1 || s[i] == s[j]) break;
        }
    }
    int sol = 0;
    for (int i = 2; i <= n + 1; i++) {
        sol = sum(sol, dp[i]);
    }
    cout << sol << '\n';
}
