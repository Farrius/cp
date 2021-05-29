#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

vector<int> g[MX], vis(MX), odd(MX);
vector<pair<int, int>> sol;
int timer = 1;

void dfs (int u, int p) {
	vis[u] = timer++;
	for (auto v : g[u]) {
		if (v == p) continue;
		if (!vis[v]) {
			dfs(v, u);
			if (odd[v]) {
				sol.emplace_back(v, u);
				odd[v] = 0;
			} else {
				sol.emplace_back(u, v);
				odd[u] ^= 1;
			}
		} else if (vis[v] < vis[u]) {
			sol.emplace_back(u, v);
			odd[u] ^= 1;
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
		if (vis[i]) continue;
		dfs(i, -1);
	}
	if (accumulate(odd.begin(), odd.end(), 0)) {
		cout << "IMPOSSIBLE" << '\n';
	} else {
		for (auto x : sol) {
			cout << x.first << ' ' << x.second << '\n';
		}
	}

}
