#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> g[n];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	vector<vector<int>> dp(1<<n, vector<int>(n, 1e9));
	dp[1][0] = 0;
	for (int i = 0; i < (1<<n); i++) {
		for (int u = 0; u < n; u++) {
			if (dp[i][u] == 1e9) continue;
			for (auto cur : g[u]) {
				int v, w;
				tie(v, w) = cur;
				if ((i>>v) & 1) continue;
				int msk = i | (1<<v);
				dp[msk][v] = min(dp[msk][v], dp[i][u] + w);
			}
		}
	}
	if (dp[(1<<n) - 1][n - 1] == 1e9) cout << -1 << '\n';
	else cout << dp[(1<<n) - 1][n - 1] << '\n';
}
