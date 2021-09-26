#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> g[n];
    for (int i = 0; i < n; i++) {
        g[i].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n);
    dp[0] = 1;
    for (int it = 0; it < k; it++) {
        int suma = 0;
        for (auto x : dp) {
            suma = (suma + x) % MOD;
        }
        vector<int> nw_dp(n);
        for (int i = 0; i < n; i++) {
            nw_dp[i] = suma;
            for (int j : g[i]) {
                nw_dp[i] = ((nw_dp[i] - dp[j]) + MOD) % MOD;
            }
        }
        swap(dp, nw_dp);
    }
    cout << dp[0] << '\n';
}
