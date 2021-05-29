#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

map<pair<int, int>, pair<int, int>> order;
set<pair<int, int>> sol;
vector<int> dist(MX, 1e9), par[MX], g[MX];
bool vis[MX];

void fn (int u) {
	for (auto v : par[u]) {
		sol.insert(order[make_pair(u, v)]);
		fn(v);
	}
}

int main () {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		order[make_pair(u, v)] = make_pair(u, v);
		order[make_pair(v, u)] = make_pair(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	q.push(a);
	dist[a] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : g[u]) {
			if (dist[v] < dist[u] + 1) continue;
			dist[v] = dist[u] + 1;
			par[v].push_back(u);
			q.push(v);
		}
	}

	fn(b);
	cout << (int) sol.size() << '\n';
	for (auto x : sol) {
		cout << x.first << ' ' << x.second << '\n';
	}
}
