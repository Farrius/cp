#include <bits/stdc++.h>

using namespace std;

int main () {
        int t;
        cin >> t;
        for (int tt = 1; tt <= t; tt++) {
                cout << "Case #" << tt << '\n';
                int n, m;
                cin >> n >> m;
                vector<pair<int, int>> g[n];
                for (int i = 0; i < m; i++) {
                        int u, v, c;
                        cin >> u >> v >> c;
                        g[u].push_back(make_pair(v, c));
                        g[v].push_back(make_pair(u, c));
                }
                pair<int, int> ex = {1e9, -1};
                vector<pair<int, int>> dist(n, ex);
                priority_queue<pair<int, int>> pq;
                vector<bool> vis(n);
                int k;
                cin >> k;
                vector<int> foc(k);
                for (int i = 0; i < k; i++) {
                        int u;
                        cin >> u;
                        dist[u].first = 0;
                        dist[u].second = u;
                        pq.push(make_pair(0, u));
                }

                while (!pq.empty()) {
                        int cur, u;
                        tie(cur, u) = pq.top();
                        pq.pop();
                        if (vis[u]) continue;
                        vis[u] = true;
                        cur = -cur;
                        for (auto cur : g[u]) {
                                int v, w;
                                tie(v, w) = cur;
                                if (dist[v].first > dist[u].first + w) {
                                        dist[v].first = dist[u].first + w;
                                        dist[v].second = dist[u].second;
                                        pq.push(make_pair(-dist[v].first, v));
                                } else if (dist[v].first == dist[u].first + w && dist[v].second > dist[u].second) {
                                        dist[v].second = dist[u].second;
                                }
                        }
                }


                int q;
                cin >> q;
                while (q--) {
                        int x;
                        cin >> x;
                        cout << "To get to " << x << ", distance " << dist[x].first << ", from city " << dist[x].second << '.' << '\n';
                }
		if (tt < t) cout << '\n';
        }
}
