#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX];

ll dp[MX][2], ar[MX][2];

void dfs (int u, int par) {
	dp[u][0] = 0;
	dp[u][1] = 0;
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][0] + abs(ar[v][0] - ar[u][0]), dp[v][1] + abs(ar[v][1] - ar[u][0]));
		dp[u][1] += max(dp[v][0] + abs(ar[v][0] - ar[u][1]), dp[v][1] + abs(ar[v][1] - ar[u][1]));
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> ar[i][0] >> ar[i][1];
			g[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, -1);
		cout << max(dp[1][0], dp[1][1]) << '\n';
	}
}
