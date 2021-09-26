#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX], dd[MX];
int up[MX][18], depth[MX], tin[MX], tout[MX];
int t = 0, n, m;

void dfs (int u) {
    tin[u] = t++;
    dd[depth[u]].push_back(tin[u]);
    for (auto v : g[u]) {
        depth[v] = depth[u] + 1;
        up[v][0] = (u == 0 ? v : u);
        dfs(v);
    }
    tout[u] = t;
}

int fn (int v, int p) {
    if (depth[v] <= p) {
        return 0;
    }
    int u = v;
    for (int i = 18; i >= 0; i--) {
        if ((p>>i) & 1) {
            v = up[v][i];
        }
    }
    auto& ar = dd[depth[u]];
    int l = lower_bound(ar.begin(), ar.end(), tin[v]) - ar.begin();
    int r = lower_bound(ar.begin(), ar.end(), tout[v]) - ar.begin();
    return r - l - 1;

}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    dfs(0);

    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= t; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    cin >> m;
    while (m--) {
        int v, p;
        cin >> v >> p;
        cout << fn(v, p) << ' ';
    }
    cout << '\n';
}
