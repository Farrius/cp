#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
int up[MX][19], n, q, depth[MX];

void dfs (int u, int p) {
    for (auto v : g[u]) {
        if (v == p) continue;
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca (int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    for (int i = 18; i >= 0; i--) {
        if (depth[b] - (1<<i) >= depth[a]) {
            b = up[b][i];
        }
    }

    if (a == b) return a;

    for (int i = 18; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    dfs(1, -1);
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            n++;
            depth[n] = depth[v] + 1;
            up[n][0] = v;
            for (int i = 1; i < 19; i++) {
                up[n][i] = up[up[n][i - 1]][i - 1];
            }
        } else {
            int a, b;
            cin >> a >> b;
            cout << lca(a, b) << '\n';
        }
    }
}
