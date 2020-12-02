#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int sol = 0, node = 0;

bool vis[MX];
vector<int> g[MX];

void dfs (int v) {
	node++;
	vis[v] = true;
	for (auto u : g[v]) {
		if (vis[u]) continue;
		dfs(u);
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
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		node = 0;
		dfs(i);
		sol = max(sol, node);
	}
	cout << sol << '\n';
}
