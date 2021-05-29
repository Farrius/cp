#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> g[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	ll mst = 0;
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, 1e9 + 7);
	vector<bool> vis(n + 1);
	dist[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int cur, u;
		tie(cur, u) = pq.top();
		pq.pop();
		cur = -cur;
		if (vis[u]) continue;
		vis[u] = true;
		mst += cur;
		for (auto vv : g[u]) {
			int v, w;
			tie(v, w) = vv;
			if (dist[v] > w) {
				dist[v] = w;
				pq.push(make_pair(-w, v));
			}
		}
	}
	cout << mst << '\n';
}
