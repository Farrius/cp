#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], cycle, par(MX), vis(MX);

void dfs (int u) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (vis[v] == 2) continue;
		if (vis[v] == 1 && (int) cycle.size() == 0) {
			int k = u;
			while (k != v) {
				cycle.push_back(k);
				k = par[k];
			}
			cycle.push_back(k);
		} else if (vis[v] == 0) {
			par[v] = u;
			dfs(v);
		}
	}
	vis[u] = 2;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cycle.clear();
		for (int i = 0; i < n; i++) {
			g[i].clear();
			vis[i] = 0;
			par[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
		}
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0) dfs(i);
		}
		reverse(cycle.begin(), cycle.end());
		if ((int) cycle.size() == 0) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
			cout << (int) cycle.size() << '\n';
			for (int i = 0; i < (int) cycle.size(); i++) {
				cout << cycle[i] + 1 << ' ';
			}
			cout << cycle[0] + 1 << '\n';
		}
	}
}
