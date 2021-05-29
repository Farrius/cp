#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[1<<20][20];
vector<int> g[20];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[v].push_back(u);
	}

	dp[1][0] = 1;
	for (int msk = 2; msk < (1<<n); msk++) {
		if (msk & (1<<(n - 1)) && msk != (1<<n) - 1) continue;
		for (int v = 0; v < n; v++) {
			if (((msk>>v) & 1) == 0) continue;
			for (auto u : g[v]) {
				if (msk>>u & 1) {
					dp[msk][v] += dp[msk-(1<<v)][u];
					dp[msk][v] %= MOD;
				}
			}
		}
	}
	cout << dp[(1<<n) - 1][n - 1] << '\n';
}
