#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int up[MX][19], tin[MX], tout[MX], depth[MX];
vector<int> g[MX], ar[MX];
int n, q, timer = 0;

void dfs (int u, int par) {
    tin[u] = ++timer;
    ar[depth[u]].push_back(timer);
    for (auto v : g[u]) {
        if (v == par) continue;
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
    tout[u] = timer;
}

int fn (int v, int h) {
    int k = depth[v];
    if (k < h) return 0;
    for (int i = 18; i >= 0; i--) {
        if ((h>>i) & 1) {
            v = up[v][i];
        }
    }
    int l = lower_bound(ar[k].begin(), ar[k].end(), tin[v]) - ar[k].begin();
    int r = lower_bound(ar[k].begin(), ar[k].end(), tout[v]) - ar[k].begin();
    if (r == (int) ar[k].size() || ar[k][r] > tout[v]) r--;
    return max(0, r - l);
}


int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    dfs(1, -1);
    up[1][0] = 1;
    for (int j = 1; j < 19; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int v, h;
        cin >> v >> h;
        cout << fn(v, h) << '\n';
    }
}
