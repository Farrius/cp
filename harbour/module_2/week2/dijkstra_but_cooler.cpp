#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> w(n + 1);
	vector<int> g[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, 1e9);
	vector<bool> vis(n + 1);
	dist[1] = w[1];
	pq.push(make_pair(-dist[1], 1));
	
	while (!pq.empty()) {
		int cur, u;
		tie(cur, u) = pq.top();
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : g[u]) {
			if (dist[v] > dist[u] + w[v]) {
				dist[v] = dist[u] + w[v];
				pq.push(make_pair(-dist[v], v));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << (i == n ? '\n' : ' ');
	}
}
