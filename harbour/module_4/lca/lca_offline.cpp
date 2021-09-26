#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e6 + 5;
const int Q = 1e7 + 5;

vector<int> g[MX], par(MX), sz(MX), top(MX);
vector<pair<int, int>> queries[Q];
vector<bool> vis(MX), ans(Q);
int n, q;
ll sol = 0;

int get (int x) {
    if (par[x] == x) return x;
    return par[x] = get(par[x]);
}

void unite (int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

void dfs (int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) {
            dfs(v);
            unite(u, v);
            top[get(u)] = u;
        }
    }

    for (auto [v, id] : queries[u]) {
        if (vis[v] && !ans[id]) {
            sol += top[get(v)];
            ans[id] = true;
        }
    }
}

int fn (int u, int d, int t, int i) {
    int x = (u * 1LL * ((i * 1LL * i) % n)) % n;
    int y = (d * 1LL * i) % n;
    int z = (x + y) % n;
    z = (z + t) % n;
    z++;
    return z;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
        top[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    queries[a1].emplace_back(b1, 1);
    queries[a2].emplace_back(b2, 2);
    queries[a3].emplace_back(b3, 3);
    queries[b1].emplace_back(a1, 1);
    queries[b2].emplace_back(a2, 2);
    queries[b3].emplace_back(a3, 3);

    for (int i = 4; i <= q; i++) {
        int a = fn(a1, a2, a3, i);
        int b = fn(b1, b2, b3, i);
        queries[a].emplace_back(b, i);
        queries[b].emplace_back(a, i);
    }

    dfs(1);
    cout << sol << '\n';
}
