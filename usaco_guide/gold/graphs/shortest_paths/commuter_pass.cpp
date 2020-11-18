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
vector<vector<int>> routes;
set<int> free_route;

int n, m, s, t, us, vs;

void update_route (int u) {
	vector<int> ruta = {t};
	while (u != -1) {
		ruta.push_back(u);
		u = par[u];
	}
	routes.push_back(ruta);
}

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
				if (v.first == t) {
					routes.clear();
					update_route(u);
				}
			} else if (v.first == t && d[v.first] == d[u] + v.second) {
				update_route(u);
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
			ll travel = d[u] + ((free_route.count(v.first) && free_route.count(u)) ? 0 : v.second);
			if (d[v.first] > travel) {
				d[v.first] = travel;
				pq.push(make_pair(-d[v.first], v.first));
			}
		}
	}
	return d[obj];
}

int main () {
	//take input
	cin >> n >> m >> s >> t >> us >> vs;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}
	//calcula el commuter pass
	dijkstra(s);
	//provar todas las rutas possibles
	ll sol = INF;
	for (auto vec : routes) {
		free_route.clear();
		for (auto x : vec) {
			cout << x << ' ';
			free_route.insert(x);
		}
		cout << '\n';
		ll cur = dijkstra2(us, vs);
		sol = min(sol, cur);
	}
	cout << sol << '\n';
}
