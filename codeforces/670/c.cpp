#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 1e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int n, cent1, cent2, par[MX], size[MX], mini = MOD, leave;
vector<int> g[MX];

void dfs (int v, int p) {
	int maxi = 0;
	par[v] = p;
	size[v] = 1;

	for (auto u: g[v]) {
		if (u == p) continue;
		dfs (u, v);
		size[v] += size[u];
		maxi = max (maxi, size[u]);
	}
	
	maxi = max (maxi, n - size[v]);

	if (maxi < mini) {
		mini = maxi;
		cent1 = v;
		cent2 = 0;
	} else if (maxi == mini) {
		cent2 = v;
	}
}

void dfs2 (int v, int p) {
	if ((int) g[v].size() == 1) {
		leave = v;
		return;
	}

	for (auto u : g[v]) {
		if (u == p) continue;
		dfs2 (u, v);
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			par[i] = 0;
		}

		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		mini = MOD;
		dfs (1, 0);

		if (!cent2) {
			cout << 1 << ' ' << g[1][0] << '\n';
			cout << 1 << ' ' << g[1][0] << '\n';
			continue;
		}

		if (par[cent1] != cent2) swap(cent1, cent2);

		dfs2 (cent1, cent2);
		
		cout << leave << ' ' << par[leave] << '\n';
		cout << leave << ' ' << cent2 << '\n';
	}
}

