#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX], gt[MX], comp(MX), c(MX), topo;
bool vis[MX];
int n, m, mn;

void dfs (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
	topo.push_back(u);
}

void dfs2 (int u) {
	vis[u] = true;
	mn = min(mn, c[u]);
	for (auto v : gt[u]) {
		if (vis[v]) continue;
		dfs2(v);
	}
}

int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		gt[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}
	memset(vis, false, sizeof(vis));
	int sol = 0;
	reverse(topo.begin(), topo.end());
	for (auto x : topo) {
		if (vis[x]) continue;
		mn = 1e9;
		dfs2(x);
		sol += mn;
	}
	cout << sol << '\n';
}
