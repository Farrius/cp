#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
map<pair<int, int>, int> id;
vector<int> edge(MX), g[MX];
vector<pair<int, int>> edges(MX);
vector<bool> vis(MX);

pair<int, int> fn (int a, int b) {
    return make_pair(min(a, b), max(a, b));
}

int va (int u, int v) {
    int in = id[fn(u, v)];
    if (edges[in].first == u) return 1;
    else return 0;
}

bool ok = true;

void dfs (int u, int par, int k) {
    if (!ok) return;
    vis[u] = true;
    for (auto v : g[u]) {
        if (v == par) continue;
        if (!vis[v]) {
            if (k == 0) edge[id[fn(u, v)]] = va(u, v);
            else edge[id[fn(u, v)]] = va(v, u);
            dfs(v, u, k ^ 1);
        } else {
            if
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
        g[u].push_back(v);
        g[v].push_back(v);
        id[fn(u, v)] = i;
    }
    dfs(1, -1, 0);
    if (!ok) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int i = 0; i < m; i++) {
            cout << edge[i];
        }
        cout << '\n';
    }
}
