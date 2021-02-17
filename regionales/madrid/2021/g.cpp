#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, s, t, p;
	while (cin >> n >> s >> t >> p) {
		s--;
		vector<pair<int, int>> g[n];
		for (int i = 0; i < p; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--; v--;
			g[v].push_back({u, w});
		}
		vector<int> dis(n, 1e9);
		dis[s] = 0;
		priority_queue<pair<int, int>> pq;
		vector<bool> vis(n);
		pq.push({0, s});
		while (!pq.empty()) {
			int u, w;
			tie(w, u) = pq.top();
			w = -w;
			pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for (auto cur : g[u]) {
				if (w + cur.second < dis[cur.first]) {
					dis[cur.first] = w + cur.second;
					pq.push({-(w + cur.second), cur.first});
				}
			}
		}
		int sol = 0;
		for (int i = 0; i < n; i++) {
			if (i == s) continue;
			if (dis[i] <= t) sol++;
		}
		cout << sol << '\n';
	}
}
