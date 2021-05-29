#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], sol(MX), cycle;
vector<bool> vis(MX);
int sz = 0;

void dfs (int u) {
	vis[u] = true;
	cycle.push_back(u);
	sz++;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		sz = 0;
		cycle.clear();
		dfs(i);
		for (auto x : cycle) {
			sol[x] = sz;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sol[i] << (i == n - 1 ? '\n' : ' ');
	}
}
