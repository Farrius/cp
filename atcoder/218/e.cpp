#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

struct edge {
    int a, b, c;
};

vector<int> par(MX), sz(MX);
vector<edge> edges;

int get (int x) {
    if (x == par[x]) return x;
    return par[x] = get(par[x]);
}

bool unite (int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
    return true;
}

bool comp (edge& u, edge& v) {
    return u.c < v.c;
}

int n, m;

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), comp);

    ll sol = 0;
    for (auto cur : edges) {
        if (!unite(cur.a, cur.b)) {
            sol += max(0, cur.c);
        }
    }
    cout << sol << '\n';
}
