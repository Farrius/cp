#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<pair<int, pair<int, int>>> edges;
vector<int> par(MX), sz(MX);
int n;

ll sol = 0;

int get (int x) {
    if (par[x] == x) return x;
    return par[x] = get(par[x]);
}

void unite (int x, int y) {
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}


int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }

    sort(edges.begin(), edges.end());

    for (auto cur : edges) {
        int u, v;
        tie(u, v) = cur.second;
        u = get(u);
        v = get(v);
        sol += cur.first * 1LL * sz[u] * 1LL * sz[v];
        unite(u, v);
    }

    cout << sol << '\n';
}
