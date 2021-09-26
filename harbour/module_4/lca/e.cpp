#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX];
int up[MX][19], depth[MX], sub[MX], n, s1, s2;

void dfs (int u, int p) {
    sub[u] = 1;
    for (auto v : g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        dfs(v, u);
        sub[u] += sub[v];
    }
}

int lca (int a, int b) {
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

    s1 = a;
    s2 = b;
    return up[a][0];
}

int fn (int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int anc = lca(a, b);

    int k = depth[a] + depth[b] - depth[anc] * 2;
    if (k % 2) return 0;
    int mk = k/2;

    for (int i = 18; i >= 0; i--) {
        if (((mk - 1)>>i) & 1) {
            b = up[b][i];
        }
    }

    if (up[b][0] == anc) {
        return n - sub[s1] - sub[s2];
    } else {
        return sub[up[b][0]] - sub[b];
    }
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
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a == b) cout << n << '\n';
        else cout << fn(a, b) << '\n';
    }
}

