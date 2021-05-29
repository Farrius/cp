#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], tin(MX), fup(MX);
set<int> sol;

int timer = 0;

void dfs (int u, int par) {
	tin[u] = ++timer;
	fup[u] = tin[u];
	int sons = 0;
	for (auto v : g[u]) {
		if (!tin[v]) {
			sons++;
			dfs(v, u);
			if (par != -1 && fup[v] >= tin[u]) {
				sol.insert(u);
			}
			fup[u] = min(fup[u], fup[v]);
		} else if (v != par) {
			fup[u] = min(fup[u], tin[v]);
		}
	}
	if (par == -1 && sons > 1) {
		sol.insert(u);
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

	dfs(1, -1);
	cout << (int) sol.size() << '\n';
	for (auto x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}
