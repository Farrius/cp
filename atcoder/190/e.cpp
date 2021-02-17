#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const int MX = 1e5 + 5;

int n, m, k;
int dist[MX][18], dp[18][1<<18], ar[18];
vector<int> g[MX];

void bfs (int idx) {
	for (int i = 1; i <= n; i++) {
		dist[i][idx] = INF;
	}
	queue<int> q;
	q.push(ar[idx]);
	dist[ar[idx]][idx] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (dist[v][idx] != INF) continue;
			dist[v][idx] = dist[u][idx] + 1;
			q.push(v);
		}
	}
}

int fn (int v, int mask) {
	if (mask == (1<<k) - 1) return 0;
	if (dp[v][mask] != -1) return dp[v][mask];
	dp[v][mask] = INF;
	for (int i = 0; i < k; i++) {
		if ((mask>>i) & 1) continue;
		dp[v][mask] = min(dp[v][mask], fn(i, mask | (1<<i)) + dist[ar[v]][i]);
	}
	return dp[v][mask];
}

int main () {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> ar[i];	
	}
	for (int i = 0; i < k; i++) {
		bfs(i);
	}
	for (int i = 0; i < k; i++) {
		if (dist[ar[0]][i] == INF) {
			cout << -1 << '\n';
			return 0;
		}
	}
	int sol = INF;
	for (int i = 0; i < k; i++) {
		sol = min(sol, 1 + fn(i, (1<<i)));
	}
	cout << sol << '\n';
}
