#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
vector<bool> vis(MX);

void dfs (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

int main () {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	a--; b--;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(a);
	if (vis[b]) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
