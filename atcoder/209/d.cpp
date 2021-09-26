#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX], p(MX), depth(MX);
int up[MX][20];
int n, q, Log = 0;

void dfs (int u, int par) {
	for (auto v : g[u]) {
		if (v == par) continue;
		up[v][0] = u;
		for (int j = 1; j < Log; j++) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
}

int lca (int u, int v) {
	int res = 0;
	if (depth[u] > depth[v]) swap(u, v);
	int k = depth[v] - depth[u];

	for (int j = Log - 1; j >= 0; j--) {
		if ((k>>j) & 1) {
			v = up[v][j];
		}
	}

	int x = u;
	if (u == v) return k;
	
	for (int j = Log - 1; j >= 0; j--) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}

	
	return k + (depth[x] - depth[up[u][0]]) * 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	while ((1<<Log) <= n) {
		Log++;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	p[1] = 1;
	dfs(1, -1);

	while (q--) {
		int u, v;
		cin >> u >> v;
		int cur = lca(u, v);
		if (cur % 2 == 0) cout << "Town" << '\n';
		else cout << "Road" << '\n';
	}
}
