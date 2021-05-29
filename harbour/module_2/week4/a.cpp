#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<bool> vis(MX);
vector<int> g[MX];
bool ok = true;

void dfs (int u, int p) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (v == p) continue;
		if (vis[v]) {
			ok = false;
			continue;
		} else {
			dfs(v, u);
		}
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n && ok; i++) {
		if (vis[i]) continue;
		dfs(i, -1);
	}
	if (ok) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
