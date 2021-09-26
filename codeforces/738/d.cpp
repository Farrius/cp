#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int n, m1, m2;

vector<int> p1(MX), p2(MX), sz1(MX), sz2(MX);

int get (int x, vector<int>& p) {
    if (p[x] == x) return x;
    return p[x] = get(p[x], p);
}

bool sameSet (int x, int y, vector<int>& p, vector<int>& sz) {
    x = get(x, p);
    y = get(y, p);
    return x == y;
}

bool unite (int x, int y, vector<int>& p, vector<int>& sz) {
    x = get(x, p);
    y = get(y, p);
    if (x == y) return false;
    if (sz1[x] < sz2[y]) swap(x, y);
    sz[x] += sz[y];
    p[y] = x;
    return true;
}

int main () {
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
        p1[i] = i;
        p2[i] = i;
        sz1[i] = 1;
        sz2[i] = 1;
    }

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v, p1, sz1);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v, p2, sz2);
    }

    vector<pair<int, int>> sol;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (sameSet(i, j, p1, sz1) || sameSet(i, j, p2, sz2)) continue;
            unite(i, j, p1, sz1);
            unite(i, j, p2, sz2);
            sol.push_back(make_pair(i, j));
        }
    }

    cout << (int) sol.size() << '\n';
    for (auto cur : sol) {
        cout << cur.first << ' ' << cur.second << '\n';
    }
}
