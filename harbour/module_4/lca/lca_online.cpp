#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX], depth(MX);
int up[MX][18], n, q;

void dfs (int u, int p) {
    up[u][0] = p;
    for (auto v : g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca (int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    for (int i = 17; i >= 0; i--) {
        if (depth[b] - (1<<i) >= depth[a]) {
            b = up[b][i];
        }
    }

    if (a == b) return a;

    for (int i = 17; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main () {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    dfs(1, -1);

    up[1][0] = 1;
    for (int i = 1; i <= 17; i++) {
        for (int u = 1; u <= n; u++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }

    int ans = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int a = x ^ ans;
        int b = y ^ ans;
        ans = lca(a, b);
        cout << ans << '\n';
    }
}
