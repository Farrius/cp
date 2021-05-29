#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 5e3 + 5;

vector<int> g[MX];
int adj[MX][MX], col[MX];
ll dist[MX][MX];
int n, m;
bool bip, vis[MX];

void dfs (int u, ll x, int c) {
	if (!bip) return;
	vis[u] = true;
	col[u] = c;
	for (int v = 0; v < n; v++) {
		if (dist[u][v] == 1e18 || dist[u][v] >= x || v == u) {
			continue;
		}
		if (!vis[v]) {
			dfs(v, x, 1 ^ c);
		} else {
			if (col[v] == col[u]) {
				bip = false;
			}
		}
	}
}

bool check (ll x) {
	memset(vis, false, sizeof(vis));
	memset(col, 0, sizeof(col));
	bip = true;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i, x, 0);
	}
	return bip;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int sol = 0;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			sol = min(sol, w);
		}
		cout << sol << '\n';
	}
}
