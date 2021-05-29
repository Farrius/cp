#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX];
vector<bool> vis(MX);
bool tree = true;
int visi = 0;

void dfs (int u, int p) {
	if (!tree) return;
	visi++;
	vis[u] = true;
	for (auto v : g[u]) {
		if (v == p) continue;
		if (vis[v]) {
			tree = false;
			return;
		}
		dfs(v, u);
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
	dfs(0, -1);
	if (visi != n) tree = false;
	if (tree) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
