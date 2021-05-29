#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 2e5 + 5;
const ll BOUND = 525600;

vector<pair<int, pair<int, int>>> g[MX];
int n, m;

bool fn (int x) {
	vector<ll> dist(n + 1, 1e9);
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	vector<bool> vis(n + 1);
	pq.push({0, 1});
	while (!pq.empty()) {
		int cur, u;
		tie(cur, u) = pq.top();
		pq.pop();
		cur = -cur;
		if (vis[u]) continue;
		for (auto e : g[u]) {
			int t = e.second.first;
			int w = e.second.second;
			int v = e.first;
			if (w < x) continue;
			if (dist[v] > dist[u] + t) {
				dist[v] = dist[u] + t;
				pq.push({-dist[v], v});
			}
		}
	}
	return dist[n] <= BOUND;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, t, w;
		cin >> u >> v >> t >> w;
		g[u].push_back(make_pair(v, make_pair(t, w)));
		g[v].push_back(make_pair(u, make_pair(t, w)));
	}

	int lo = 0, hi = 1e9;
	int sol = lo;
	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		if (fn(mid)) {
			sol = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << sol << '\n';
}
