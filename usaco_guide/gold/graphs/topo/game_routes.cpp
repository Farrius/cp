#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
 
int n, m;
vector<int> g[MX], reverseG[MX], dp(MX), degree(MX);
 
void fn () {
        queue<int> q;
        for (int i = 0; i < n; i++) {
                if (degree[i] == 0) q.push(i);
        }
 
        while(!q.empty()) {
                int v = q.front();
                if (v == 0) dp[v] = 1;
                q.pop();
                for (int u : g[v]) {
                        degree[u]--;
                        if (degree[u] == 0) q.push(u);
                        dp[u] = (dp[u] + dp[v]) % MOD;
                }
        }
}
 
int main () {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                u--; v--;
                g[u].push_back(v);
                degree[v]++;
                reverseG[v].push_back(u);
        }
 
        fn();
        cout << dp[n - 1] << '\n';
}
