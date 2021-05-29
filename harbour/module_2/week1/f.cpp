#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> g[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int sol = 1e9;

	for (int i = 1; i <= n; i++) {
		queue<int> q;
		vector<int> dist(n + 1, -1);
		dist[i] = 0;
		q.push(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : g[u]) {
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				} else if (dist[v] >= dist[u]) {
					sol = min(sol, dist[u] + dist[v] + 1);
				}
			}
		}
	}

	cout << (sol == 1e9 ? -1 : sol) << '\n';
}
