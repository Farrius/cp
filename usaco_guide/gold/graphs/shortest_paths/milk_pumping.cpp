#include <bits/stdc++.h>

using namespace std;

const int MX = 1e3;
const int INF = 1e9 + 7;

vector<pair<int, pair<int, int>>> g[MX];
int n, m;

int dijkstra (int tope) {
	vector<int> dist(n, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({0, 0});
	dist[0] = 0;
	while (!pq.empty()) {
		int w, u;
		tie(w, u) = pq.top();
		w = -w;
		pq.pop();
		if (dist[u] != w) continue;
		for (auto v : g[u]) {
			if (v.second.second < tope) continue;
			if (dist[v.first] > dist[u] + v.second.first) {
				dist[v.first] = dist[u] + v.second.first;
				pq.push({-dist[v.first], v.first});
			}
		}
	}
	if (dist[n - 1] == INF) dist[n - 1] = -1;
	return dist[n - 1];
}

int main () {
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);

	cin >> n >> m;
	set<int> st;
	for (int i = 0; i < m; i++) {
		int u, v, c, f;
		cin >> u >> v >> c >> f;
		u--; v--;
		g[u].push_back({v, make_pair(c, f)});
		g[v].push_back({u, make_pair(c, f)});
		st.insert(f);
	}
	int sol = 0;
	for (auto x: st) {
		int cur = dijkstra(x);
		if (cur == -1) continue;
		sol = max(sol, (int) (x * 1e6)/cur);
	}
	cout << sol << '\n';
}
