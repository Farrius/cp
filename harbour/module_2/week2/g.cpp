#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 1e5 + 5;

vector<pair<int, int>> g[MX];

vector<int> dij (int n, int x) {
	vector<int> dist(n + 1, 1e9 + 7);
	priority_queue<pair<int, int>> pq;
	vector<bool> vis(n + 1);
	dist[x] = 0;
	pq.push({0, x});
	while (!pq.empty()) {
		int cur, u;
		tie(cur, u) = pq.top();
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto e : g[u]) {
			int v, w;
			tie(v, w) = e;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({-dist[v], v});
			}
		}
	}
	return dist;
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	vector<int> dis1 = dij(n, 1);
	vector<int> dis2 = dij(n, 2);
	vector<pair<int, int>> diff;
	for (int i = 3; i <= n; i++) {
		diff.push_back(make_pair(dis1[i] - dis2[i], i));
	}
	sort(diff.begin(), diff.end());
	ll sol = 0;
	for (int i = 0; i < n - 2; i++) {
		if (i < (n - 2)/2) {
			sol += dis1[diff[i].second] * 2;
		} else {
			sol += dis2[diff[i].second] * 2;
		}
	}
	cout << sol << '\n';
}
