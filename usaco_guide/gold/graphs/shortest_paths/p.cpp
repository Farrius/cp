#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int MX = 1e5 + 5;
const ll INF = 1e18;
 
vector<pair<int, int>> g[MX];
vector<ll> d(MX, INF);
vector<int> par(MX, -1);
priority_queue<pair<ll, int>> pq;
bool vis[MX];
set<pair<int, int>> free_route;
 
void dijkstra (int source) {
	d[source] = 0;
	pq.push(make_pair(0, source));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : g[u]) {
			if (d[v.first] > d[u] + v.second) {
				d[v.first] = d[u] + v.second;
				pq.push(make_pair(-d[v.first], v.first));
				par[v.first] = u;
			}
		}
	}
}
 
ll dijkstra2 (int source, int obj) {
	fill(d.begin(), d.end(), INF);
	memset(vis, false, sizeof(vis));
	d[source] = 0;
	pq.push(make_pair(0, source));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : g[u]) {
			ll travel = d[u] + (free_route.count(make_pair(u, v.first)) ? 0 : v.second);
			if (d[v.first] > travel) {
				d[v.first] = travel;
				pq.push(make_pair(-d[v.first], v.first));
			}
		}
	}
	return d[obj];
}
 
int main () {
	int n, m, s, t, us, vs;
	cin >> n >> m >> s >> t >> us >> vs;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}
	dijkstra(s);
	int k = t;
	while (par[k] != -1) {
		free_route.insert(make_pair(k, par[k]));
		free_route.insert(make_pair(par[k], k));
		k = par[k];
	}
	ll sol = dijkstra2(vs, us);
	cout << sol << '\n';
}
