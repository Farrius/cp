#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 1e5 + 5;
const ll INF = 1e18;

int n, m;
vector<pair<int, int>> g[MX], rg[MX];
vector<ll> d(MX, INF), rd(MX, INF);
map<pair<int, int>, int> edges;

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g[u].push_back({v, w});
		rg[v].push_back({u, w});
		edges[make_pair(u, v)] = w;
	}

	auto dijkstra = [] (vector<pair<int, int>> g[MX], vector<ll>& d, int start) {
		priority_queue<pair<ll, int>> pq;
		pq.push({0, start});
		d[start] = 0;
		while (!pq.empty()) {
			int u; ll w;
			tie(w, u) = pq.top();
			w = -w;
			pq.pop();
			if (w != d[u]) continue;
			for (auto v: g[u]) {
				if (d[v.first] > d[u] + v.second) {
					d[v.first] = d[u] + v.second;
					pq.push({-d[v.first], v.first});
				}
			}
		}
	};
	dijkstra(g, d, 0);
	dijkstra(rg, rd, n - 1);
	//take the minimum route
	ll sol = INF;
	for (auto cur : edges) {
		sol = min(sol, d[cur.first.first] + (cur.second/2) + rd[cur.first.second]);
	}
	cout << sol << '\n';
}
