#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], sol;
int n;

void dfs (int u, int par) {
    sol.push_back(u);
    sort(g[u].begin(), g[u].end());
    for (auto v : g[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    if (par > 0) sol.push_back(par);
}

int main () {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);
    for (auto x : sol) {
        cout << x << ' ';
    }
    cout << '\n';
}
