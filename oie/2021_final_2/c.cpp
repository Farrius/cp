#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX];
int sol = 0;


int dfs (int u, int par, int take) {
	int cur = take;
	int x = -1, y = -1;
	for (auto v : g[u]) {
		if (v == par) continue;
		if (x == -1) {
			x = v;
		} else {
			y = v;
		}
	}
	if (x == -1) {
		return cur;
	} else if (y == -1) {
		cur += dfs(x, u, 1);
	} else {
		if ((int) g[x].size() < g[y].size()) {
			cur += 2 * min(dfs(x, u, 1), dfs(y, u, 1));
		} else if ((int) g[x].size() > g[y].size()) {
			cur += 2 * min(dfs(x, u, 1), dfs(y, u, 1));
		} else {
			cur += 2 * min(dfs(x, u, 1), dfs(y, u, 1));
		}
	}
	return cur;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		sol = 0;
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << dfs(0, -1, 1) << '\n';
	}
}
