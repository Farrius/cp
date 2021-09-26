#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX =  2e5 + 5;
vector<pair<int, int>> g[MX];
bool vis[MX];
stack<int> stck;
vector<int> sol;

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    int u = -1, v = -1;
    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() % 2 == 0) continue;
        if (v != -1) {
            cout << "NO" << '\n';
            return 0;
        } else if (u == -1) {
            u = i;
        } else {
            v = i;
        }
    }

    if (u == -1) u = 1;

    stck.push(u);
    while (true) {
        while (!g[u].empty() && vis[g[u].back().second]) {
            g[u].pop_back();
        }
        
        if (g[u].empty()) {
            sol.push_back(u);
            stck.pop();
            if (stck.empty()) break;
            u = stck.top();
        } else {
            vis[g[u].back().second] = true;
            u = g[u].back().first;
            stck.push(u);
        }
    }

    if ((int) sol.size() != m + 1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (auto x : sol) cout << x << ' ';
        cout << '\n';
    }
}
