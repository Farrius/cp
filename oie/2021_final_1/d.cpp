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
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u][v] = w;
			adj[v][u] = w;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) dist[i][j] = 0;
				else if (adj[i][j]) dist[i][j] = adj[i][j];
				else dist[i][j] = 1e18;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		ll lo = 1, hi = 1e18 + 8;
		ll sol = 1;
		while (lo <= hi) {
			ll mid = lo + (hi - lo)/2;
			if (check(mid)) {
				sol = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (sol == 1e18 + 8) cout << "INF" << '\n';
		else cout << sol << '\n';
	}
}
