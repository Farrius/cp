#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int n, sol = 0;
vector<int> g[MX];

pair<int, int> dfs (int u, int par) {
    if (g[u].size() == 1 && u != 1) {
        return {1, 1};
    }
    vector<pair<int, int>> juntar, luego;
    for (auto v : g[u]) {
        if (v == par) continue;
        auto cur = dfs(v, u);
        if (cur.first == 1) juntar.push_back(cur);
        else luego.push_back(cur);
    }
    for (auto cur : luego) {
        juntar.push_back(cur);
    }

    int leafs = 0;
    int m = (int) juntar.size();
    for (int i = 0; i < m; i++) {
        leafs += juntar[i].second;
        if (juntar[i].first == 0 && i > 0) leafs--;
    }

    bool inp = false;
    for (int i = 0; i < m; i++) {
        if (juntar[i].first == 1) inp = true;
    }
    
    int nxt = 1;
    if (inp) nxt = 0;

    return make_pair(nxt, leafs);
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cout << dfs(1, -1).second << '\n';

    }
}
