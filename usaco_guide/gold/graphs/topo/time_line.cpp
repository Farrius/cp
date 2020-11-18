#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<pair<int, int>> g[MX];
vector<int> degree(MX), dist(MX);
int n, m, c;

void fn () {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (degree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (dist[v.first] < dist[u] + v.second) {
				dist[v.first] += dist[u] + v.second - dist[v.first];
			}
			degree[v.first]--;
			if (degree[v.first] == 0) q.push(v.first);
		}
	}
}

int main () {
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);

	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> dist[i];
	}

	for (int i = 0; i < c; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		u--; v--;
		g[u].push_back(make_pair(v, k));
		degree[v]++;
	}
	
	fn();

	for (int i = 0; i < n; i++) {
		cout << dist[i] << '\n';
	}
}
