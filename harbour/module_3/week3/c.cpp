#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
int n, sub[MX], depth[MX];
ll dis[MX];

void dfs (int u, int par) {
	sub[u] = 1;
	for (auto v : g[u]) {
		if (v == par) continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		sub[u] += sub[v];
	}
}

void dfs2 (int u, int par) {
	if (par != -1) {
		dis[u] = dis[par];
		dis[u] -= sub[u];
		dis[u] += n - sub[u];
	}
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs2(v, u);
	}
}

int main () {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		dis[1] += depth[i];
	}
	dfs2(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << (i == n ? '\n' : ' ');
	}
}
