#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> ar(25), g[25];
ll sol = -1;
int n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			g[i].clear();
			cin >> ar[i];
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<ll> dp(1<<n, -1);
		dp[1] = ar[0];
		for (int msk = 1; msk < 1<<n; msk++) {
			if (dp[msk] == -1) continue;
			for (int i = 0; i < n; i++) {
				if ((msk>>i) & 1) {
					for (auto v : g[i]) {
						if (ar[v] >= dp[msk] || (msk>>v) & 1) continue;
						dp[msk|(1<<v)] = max(dp[msk|(1<<v)], 2 * dp[msk] + ar[v]);
					}
				}
			}
		}
		cout << dp[(1<<n) - 1] << '\n';
	}
}
