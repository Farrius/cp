#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ways(n), dist(n, 1e9);
    vector<bool> vis(n);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    ways[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto v : g[u]) {
            if (dist[u] + 1 <= dist[v]) {
                dist[v] = dist[u] + 1;
                ways[v] = (ways[v] + ways[u]) % MOD;
                q.push(v);
            }
        }
    }

    cout << ways[n - 1] << '\n';
}
