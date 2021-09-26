#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], dist(MX), leafs, p(MX);
vector<bool> ok(MX), vis(MX);
int n, sol = 0;

void dfs (int u, int par) {
	p[u] = par;
	for (auto v : g[u]) {
		if (v == par) continue;
		dist[v] = dist[u] + 1;
		dfs(v, u);
	}
}

int main () {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, -1);
	set<pair<int, int>> ver;
	for (int i = 1; i <= n; i++) {
		if (dist[i] <= 1) {
			vis[i] = true;
		} else {
			if (dist[i] > 2) ver.insert(make_pair(dist[i], i));
		}
	}

	while (!ver.empty()) {
		auto it = ver.rbegin();
		int u = it->second;
		ver.erase(make_pair(it->first, u));
		if (vis[u]) continue;
		sol++;
		vis[u] = true;
		vis[p[u]] = true;
		for (auto v : g[p[u]]) {
			vis[v] = true;
		}
	}

	cout << sol << '\n';
}
