#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
int n, dp[MX];
int centro = -1;

void dfs (int u, int par) {
	dp[u] = 1;
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		dp[u] += dp[v];
	}
}

void dfs2 (int u, int par) {
	bool ok = true;
	for (auto v : g[u]) {
		if (par == v) continue;
		if (dp[v] > n/2) ok = false;
		dfs2(v, u);
	}
	if (u != 1 && dp[1] - dp[u] > n/2) ok = false;
	if (ok) centro = u;
}


int main () {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	dfs2(1, -1);
	cout << centro << '\n';
}
