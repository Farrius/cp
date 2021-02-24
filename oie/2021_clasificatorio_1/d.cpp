#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

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
		int sol = 0;
		priority_queue<pair<int, int>> pq;
		vector<bool> vis(n);
		pq.push({0, 0});
		while (!pq.empty()) {
			int u, w;
			tie(w, u) = pq.top();
			pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
			sol = max(sol, -w);
			for (auto cur : g[u]) {
				if (vis[cur.first]) continue;
				pq.push({-cur.second, cur.first});
			}
		}
		cout << sol << '\n';
	}
}
