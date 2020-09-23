#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int main () {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w",stdout);

	ll n, m, c;
	cin >> n >> m >> c;
	ll ar[MX], dp[MX][MX];
	vector<pair<int, int>> edges;

	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges.push_back({a, b});
	}
	ll sol = 0;
	memset(dp, -1, sizeof(dp));
	dp[0][1] = 0;

	for (int t = 1; t < MX; t++) {
		for (auto x: edges) {
			int a, b;
			a = x.first;
			b = x.second;
			if (dp[t - 1][a] >= 0) {
				dp[t][b] = max (dp[t][b], dp[t - 1][a] + ar[b]);
			}
		}
		sol = max (sol, dp[t][1] - c * t * t);
	}
	
	cout << sol << '\n';
}
