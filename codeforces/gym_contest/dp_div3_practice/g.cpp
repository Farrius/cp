#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	freopen("longpath.in", "r", stdin);
	freopen("longpath.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> g[n], deg(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[v].push_back(u);
		deg[u]++;
	}
	vector<int> dp(n, 0);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		sol = max(sol, dp[i]);
	}
	cout << sol << '\n';
}
