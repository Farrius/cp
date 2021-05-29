#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], col(MX), cnt(2);
bool bip = true, vis[MX];

void dfs (int u) {
	if (!bip) return;
	vis[u] = true;
	cnt[col[u]]++;
	for (auto v : g[u]) {
		if (vis[v]) {
			if (col[u] == col[v]) bip = false;
			continue;
		}
		col[v] = col[u] ^ 1;
		dfs(v);
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
	dfs(1);
	if (!bip) {
		cout << -1 << '\n';
	} else {
		ll sol = 0;
		for (int i = 1; i <= n; i++) {
			if (col[i] == 0) continue;
			sol += cnt[0] - (int) g[i].size();
		}
		cout << sol << '\n';
	}
}
