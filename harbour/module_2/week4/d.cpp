#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int bridges = 0;
int fup[MX], tin[MX], timer = 0;
vector<int> g[MX];

void dfs (int u, int par) {
	tin[u] = ++timer;
	fup[u] = tin[u];
	for (auto v : g[u]) {
		if (!tin[v]) {
			dfs(v, u);
			fup[u] = min(fup[u], fup[v]);
			if (fup[v] > tin[u]) {
				bridges++;
			}
		} else if (v != par) {
			fup[u] = min(fup[u], tin[v]);
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
	for (int i = 1; i <= n; i++) {
		if (tin[i]) continue;
		dfs(i, -1);
	}
	cout << m - bridges << '\n';
}
