#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 5e4 + 5;
const ll INF = 1e18;

vector<pair<int, int>> g[MX];
vector<ll> dist(MX, INF), realdist(MX, INF);
bool vis[MX];
int haybale[MX], ar[MX];
int n, m, k;

void dijkstra (int source) {
	priority_queue<pair<ll, int>> pq;
	pq.push(make_pair(0, source));
	dist[source] = 0;
	while (!pq.empty()) {
		int v;
		v = pq.top().second;
		pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (auto u : g[v]) {
			if (dist[u.first] >= dist[v] + u.second) {
				dist[u.first] = dist[v] + u.second;
				pq.push(make_pair(-dist[u.first], u.first));
			}
		}
	}
}

int main () {
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	for (int i = 0; i < k; i++) {
		cin >> haybale[i] >> ar[i];
		haybale[i]--;
	}
	dijkstra(n - 1);
	realdist = dist;
	for (int i = 0; i < k; i++) {
		g[n].push_back(make_pair(haybale[i], realdist[haybale[i]] - ar[i]));
	}
	dist = vector<ll>(MX, INF);
	memset(vis, false, sizeof(vis));
	dijkstra(n);
	for (int i = 0; i < n - 1; i++) {
		cout << (dist[i] <= realdist[i]) << '\n';
	}
}
