#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

vector<int> par(MX), sz(MX);
vector<bool> vis(MX);

int power (int n, int k) {
    int res = 1;
    while (k) {
        if (k % 2) res = (res * 1LL * n) % MOD;
        n = (n * 1LL * n) % MOD;
        k /= 2;
    }
    return res;
}

int sub (int a, int b) {
    int c = a - b;
    if (c < 0) c += MOD;
    return c;
}

int get (int x) {
    if (par[x] == x) return x;
    return par[x] = get(par[x]);
}

void unite (int x, int y) {
    x = get(x);
    y = get(y);
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    int sol = power(n, k);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 1) continue;
        unite(u, v);
    }

    for (int i = 1; i <= n; i++) {
        int z = get(i);
        if (vis[z]) continue;
        vis[z] = true;
        sol = sub(sol, power(sz[z], k));
    }

    cout << sol << '\n';
}
