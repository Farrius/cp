#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> type(MX);
vector<pair<int, int>> g[MX];
int r = 0;

void dfs (int u, int par, int last) {
    int cur = last%r + 1;
    for (auto [v, id] : g[u]) {
        if (v == par) continue;
        type[id] = cur;
        dfs(v, u, cur);
        cur = cur%r + 1;
    }
}

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(make_pair(v, i));
        g[v].push_back(make_pair(u, i));
    }

    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 1);
    sort(nodes.begin(), nodes.end(), [&] (int a, int b) { return (int) g[a].size() > (int) g[b].size();});

    r = (int) g[nodes[k]].size();

    dfs(1, -1, 0);

    cout << r << '\n';
    for (int i = 0; i < n - 1; ++i) {
        cout << type[i] << ' ';
    }
    cout << '\n';
}
