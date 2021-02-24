#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, ll>> g[n];
		vector<vector<int>> ma(n, vector<int>(n, 1e9));
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			ma[u][v] = min(ma[u][v], w);
		}
		vector<ll> dist(n, 1e18);
		dist[0] = 0;
		vector<bool> vis(n);
		priority_queue<pair<pair<ll, int>, vector<int>>> pq;
		vector<int> cur;
		pq.push(make_pair(make_pair(0, 0), cur));
		while (!pq.empty()) {
			int u;
			ll w;
			tie(w, u) = pq.top().first;
			cur = pq.top().second;
			pq.pop();
			for (auto v : g[u]) {
				ll baq = 0;
				int m = (int) cur.size();
				for (int i = 0; i < m; i++) {
					baq += cur[i] * 2;
				}
				baq += v.second;
				cur.push_back(v.second);
				if (dist[v.first] > v.second + dist[u]) {
					dist[v.first] = v.second + dist[u];
					pq.push(make_pair(make_pair(-dist[v.first], v.first), cur));
				}
				cur.pop_back();
			}
		}
		for (int i = 1; i < n; i++) {
			if (dist[i] == 1e18) {
				cout << -1;
			} else {
				cout << dist[i];
			}
			cout << (i == n - 1 ? '\n' : ' ');
		}
	}
}
