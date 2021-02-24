#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct Train {
	int w, k, e;
};

int main () {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	x--; y--;
	vector<Train> g[n];
	for (int i = 0; i < m; i++) {
		int u, v, t, r;
		cin >> u >> v >> t >> r;
		u--; v--;
		Train cur;
		cur.e = v; cur.k = r; cur.w = t;
		g[u].push_back(cur);
		cur.e = u;
		g[v].push_back(cur);
	}
	vector<ll> dist(n, 1e18);
	vector<bool> vis(n);
	priority_queue<pair<ll, int>> pq;
	dist[x] = 0;
	pq.push({0, x});
	while (!pq.empty()) {
		int u;
		u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto cur : g[u]) {
			ll espera = 0;
			if (dist[u] % cur.k != 0) {
				espera += cur.k - (dist[u] % cur.k);
			}
			if (dist[cur.e] > dist[u] + espera + cur.w) {
				dist[cur.e] = dist[u] + espera + cur.w;
				pq.push({-dist[cur.e], cur.e});
			}
		}
	}
	if (dist[y] == 1e18) cout << -1 << '\n';
	else cout << dist[y] << '\n';

}
