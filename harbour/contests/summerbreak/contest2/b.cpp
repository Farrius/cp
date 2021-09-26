#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
bool ok = false;
int cnt = 0, root = -1, n, m;
bool vis[MX];

void dfs (int u, int par) {
	vis[u] = true;
	if ((int) g[u].size() > 2) cnt = 10;
	for (auto v : g[u]) {
		if (v == root && v != par) cnt++;
		if (vis[v]) continue;
		dfs(v, u);
		break;
	}
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int sol = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		cnt = 0;
		root = i;
		dfs(i, -1);
		if (cnt == 1) sol++;
	}
	cout << sol << '\n';
}
