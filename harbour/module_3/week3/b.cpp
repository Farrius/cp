#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
int n;
ll ar[MX], dp[MX][2];
vector<int> g[MX];

void dfs (int u, int par) {
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}
	dp[u][1] = ar[u];
	for (auto v : g[u]) {
		if (v == par) continue;
		dp[u][1] += dp[v][0];
	}
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
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
