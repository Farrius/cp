#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 1e4 + 5;

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
		vector<bool> vis(n);
		ll mst = 0;
		while (!pq.empty()) {
			int u, w;
			tie(w, u) = pq.top();
			pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
			mst += -w;
			for (auto cur : g[u]) {
				if (!vis[cur.first]) pq.push({-cur.second, cur.first});
			}
			
		}
		cout << mst << '\n';
	}
}
