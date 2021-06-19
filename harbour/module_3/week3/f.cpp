#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int sub[MX], c[MX], sol[MX];
vector<int> g[MX];
set<int> col[MX];

void dfs (int u, int par) {
	sub[u] = 1;
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		sub[u] += sub[v];
	}
	if (par != -1) g[u].erase(find(g[u].begin(), g[u].end(), par));
	sort(g[u].begin(), g[u].end(), [&] (int a, int b) {return sub[a] > sub[b];});
}

void dfs1 (int u, int par) {
	if ((int) g[u].size() == 0) {
		col[u].insert(c[u]);
		sol[u] = 1;
		return;
	}
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs1(v, u);
	}
	for (int i = 1; i < (int) g[u].size(); i++) {
		for (auto x : col[g[u][i]]) {
			col[g[u][0]].insert(x);
		}
		col[g[u][i]].clear();
	}
	col[u] = move(col[g[u][0]]);
	col[u].insert(c[u]);
	col[g[u][0]].clear();
	sol[u] = (int) col[u].size();
}

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	dfs1(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << sol[i] << (i == n ? '\n' : ' ');
	}
}
