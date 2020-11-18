#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 3e18;
const int MX = 1e5 + 5;

vector<ll> dist(MX, INF);
vector<pair<int, int>> g[MX];
bool vis[MX];

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--; 
		g[u].push_back(make_pair(v, w));
	}

	dist[0] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : g[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(make_pair(-dist[v.first], v.first));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << dist[i] << (i == n - 1 ? '\n' : ' ');
	}
}
