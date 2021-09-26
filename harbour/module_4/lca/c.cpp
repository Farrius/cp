#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<pair<int, int>> g[MX];
int up[MX][19], depth[MX], n, q, w[MX], ps[MX];
ll pref[MX];

void dfs (int u, int p) {
    if (p != -1) {
        pref[u] += pref[p];
        up[u][0] = p;
    }
    for (auto [v, ww] : g[u]) {
        if (v == p) continue;
        pref[v] = ww;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

ll lca (int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int aa = a;
    int bb = b;
    for (int i = 18; i >= 0; i--) {
        if (depth[b] - (1<<i) >= depth[a]) {
            b = up[b][i];
        }
    }
    
    int anc = -1;
    if (a == b) {
        anc = a;
    } else {
        for (int i = 18; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        anc = up[a][0];
    }

    ll res = pref[aa] + pref[bb];
    res -= pref[anc] * 2LL;
    return res;
}

int main () {
    cin >> n >> q;
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; i++) {
        cin >> ps[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 2; i <= n; i++) {
        g[i].emplace_back(ps[i], w[i]);
        g[ps[i]].emplace_back(i, w[i]);
    }

    dfs(1, -1);
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
