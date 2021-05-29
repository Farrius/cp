#include <bits/stdc++.h>

using namespace std;

int main () {
        int n, m;
        while (cin >> n >> m) {
                vector<pair<int, int>> g[n];
                for (int i = 0; i < m; i++) {
                        int u, v, c;
                        cin >> u >> v >> c;
                        g[u].push_back(make_pair(v, c));
                }
                vector<int> dist(n, 1e9);
                int x, y;
                cin >> x >> y;
                dist[x] = 0;
                priority_queue<pair<int, int>> pq;
                vector<bool> vis(n);
                pq.push(make_pair(0, x));

                while (!pq.empty()) {
                        int cur, u;
                        tie(cur, u) = pq.top();
                        pq.pop();
                        if (vis[u]) continue;
                        cur = -cur;
                        for (auto cur : g[u]) {
                                int v, w;
                                tie(v, w) = cur;
                                if (dist[v] > dist[u] + w) {
                                        dist[v] = dist[u] + w;
                                        pq.push(make_pair(-dist[v], v));
                                }
                        }
                }

                if (dist[y] == 1e9) cout << "no path from " << x << " to " << y << '\n';
                else cout << dist[y] << '\n';
        }
}
