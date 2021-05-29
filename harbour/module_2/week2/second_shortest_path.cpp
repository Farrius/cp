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
	}
 
	vector<vector<int>> dist(n + 1, vector<int>(2, 1e9 + 7));
	vector<int> vis(n + 1);
	priority_queue<pair<int, int>> pq;
	dist[1][0] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int cur, u;
		tie(cur, u) = pq.top();
		pq.pop();
		if (vis[u] > 1) continue;
		for (auto edge : g[u]) {
			int v, w;
			tie(v, w) = edge;
			int nxt = dist[u][vis[u]] + w;
			if (dist[u][vis[u]] + w < dist[v][0]) {
				dist[v][1] = dist[v][0];
				dist[v][0] = nxt;
				pq.push(make_pair(-dist[v][0], v));
				pq.push(make_pair(-dist[v][1], v));
			} else if (dist[u][vis[u]] + w < dist[v][1] && dist[u][vis[u]] + w != dist[v][0]) {
				dist[v][1] = nxt;
				pq.push(make_pair(-dist[v][1], v));
			}
		}
		vis[u]++;
	}
 
	if (dist[n][1] == 1e9 + 7) cout << -1 << '\n';
	else cout << dist[n][1] << '\n';
}
