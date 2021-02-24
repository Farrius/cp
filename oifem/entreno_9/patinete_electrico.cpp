#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> g[n];
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		priority_queue<pair<int, int>> pq;
		pq.push({0, 0});
		vector<int> dist(n, 1e9);
		dist[0] = 0;
		vector<bool> vis(n);
		while (!pq.empty()) {
			int w, u;
			tie(w, u) = pq.top();
			pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for (auto v : g[u]) {
				if (dist[v.first] > dist[u] + v.second) {
					dist[v.first] = dist[u] + v.second;
					pq.push({-dist[v.first], v.first});
				}
			}
		}
		cout << dist[1] << '\n';
	}
}
