#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int u, v, w;
    node (int uu, int vv, int ww) {
        u = uu;
        v = vv;
        w = ww;
    }
};

int n, m;
vector<node> edges;

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        node cur(u, v, w);
        edges.push_back(cur);
    }
    int start = 0;
    vector<int> dist(n + 1, 1e9), dist1(n + 1, 1e9), par(n + 1);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        start = 0;
        for (auto cur : edges) {
            if (dist[cur.u] + cur.w < dist[cur.v]) {
                start = cur.v;
                dist[cur.v] = dist[cur.u] + cur.w;
                par[cur.v] = cur.u;
            }
        }
    }

    if (start == 0) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) start = par[start];
        vector<int> sol;
        sol.push_back(start);
        start = par[start];
        while (start != sol[0]) {
            sol.push_back(start);
            start = par[start];
        }

        reverse(sol.begin(), sol.end());
        cout << (int) sol.size() << '\n';
        for (auto x : sol) cout << x << ' ';
        cout << '\n';
    }

}
