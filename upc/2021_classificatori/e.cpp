#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<pair<int, int>> g[MX];
int llega[MX];
bool vis[MX];
bool ok = true;

void dfs (int u, int x, int par) {
	if (!ok) return;
	vis[u] = true;
	llega[u] = x;
	for (auto cur : g[u]) {
		int v, w;
		tie(v, w) = cur;
		if (v == par) continue;
		if (vis[v]) {
			if (w * x * llega[v] < 0) ok = false;
		} else {
			dfs(v, x * w, u);
		}
	}
}

int main () {
	int n, m;
	while (cin >> n >> m) {
		ok = true;
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; i++) {
			llega[i] = 1;
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			dfs(i, 1, -1);
		}
		if (ok) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}
