#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 4e18;

int main () {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> ma(n, vector<ll>(n, INF));
	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		ma[u][v] = min(ma[u][v], w);
		ma[v][u] = min(ma[v][u], w);
	}
	
	ll dp[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dp[i][j] = 0;
			else if (ma[i][j] != -1) dp[i][j] = ma[i][j];
			else dp[i][j] = INF;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[i][k] == INF || dp[k][j] == INF) continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (dp[a][b] == INF) cout << -1 << '\n';
		else cout << dp[a][b] << '\n';
	}
}
