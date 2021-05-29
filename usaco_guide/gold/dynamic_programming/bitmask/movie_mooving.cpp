#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);  
	int n;
	ll l;
	cin >> n >> l;
	ll w[n];
	vector<ll> g[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			g[i].push_back(x);
		}
	}
	vector<ll> dp((1<<n), -1);
	dp[0] = 0;
	for (int msk = 0; msk < (1<<n); msk++) {
		for (int i = 0; i < n; i++) {
			if ((msk>>i) & 1) continue;
			int j = upper_bound(g[i].begin(), g[i].end(), dp[msk]) - g[i].begin();
			if (j > 0) dp[msk|(1<<i)] = max(dp[msk|(1<<i)], g[i][j - 1] + w[i]);
		}
	}
	int sol = 23;
	for (int msk = 0; msk < (1<<n); msk++) {
		if (dp[msk] >= l) {
			sol = min(sol, __builtin_popcount(msk));
		}
	}
	if (sol == 23) cout << -1 << '\n';
	else cout << sol << '\n';
}
