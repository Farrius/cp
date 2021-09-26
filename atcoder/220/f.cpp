#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], sub(MX);
vector<ll> dis(MX);
int n;

void dfs (int u, int par) {
    sub[u] = 1;
    for (auto v : g[u]) {
        if (v == par) continue;
        dfs(v, u);
        sub[u] += sub[v];
        dis[u] += dis[v] + sub[v];
    }
}

void dfs1 (int u, int par) {
    if (par != -1) {
        dis[u] = dis[par] - sub[u] + (n - sub[u]);
    }
    for (auto v : g[u]) {
        if (v == par) continue;
        dfs1(v, u);
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);
    dfs1(1, -1);

    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << '\n';
    }
}
