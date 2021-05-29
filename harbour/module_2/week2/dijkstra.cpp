#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> g[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, 1e9);
	dist[1] = 0;
	pq.push(make_pair(0, 1));
	vector<bool> vis(n + 1);
	while (!pq.empty()) {
		int u, w;
		tie(w, u) = pq.top();
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		w = -w;
		for (auto cur : g[u]) {
			int v, ww;
			tie(v, ww) = cur;
			if (dist[v] > dist[u] + ww) {
				dist[v] = dist[u] + ww;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << (i == n ? '\n' : ' ');
	}
}
