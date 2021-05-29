#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int u;
    int v;
    int w;
};

vector<node> edges;
int n, m, fins;

void dfs (int u, int x) {
    fins = max(fins, u);
    int nxt = -1;
    for (auto cur : edges) {
        if (cur.w > x) continue;
        if (cur.v <= u) continue;
        if (u >= cur.u) nxt = max(nxt, cur.v);
    }
    if (nxt <= fins) return;
    dfs(nxt, x);
}

bool fn (int x) {
    fins = 0;
    dfs(1, x);
    return fins == n;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        node cur;
        cin >> cur.u >> cur.v >> cur.w;
        edges[i] = cur;
    }
    int lo = 0, hi = 1e9 + 7;
    int sol = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (fn(mid)) {
            sol = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << sol << '\n';
}
