#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
set<pair<int, int>> edges;
vector<bool> vis(MX);
ll sz = 0;

void dfs (int u) {
	vis[u] = true;
	sz++;
	for (auto v : g[u]) {
		edges.insert(make_pair(min(u, v), max(u, v)));
		if (vis[v]) continue;
		dfs(v);
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		edges.clear();
		sz = 0;
		dfs(i);
		sol += sz * (sz - 1)/2LL - (ll) edges.size();
	}
	cout << sol << '\n';
}
