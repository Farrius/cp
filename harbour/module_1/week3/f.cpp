#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX], sol(MX), topo; 
int vis[MX];
bool cycle = false;

void dfs (int u) {
	if (cycle) return;
	vis[u] = 1;
	for (auto v : g[u]) {
		if (vis[v] == 2) continue;
		if (vis[v]) {
			cycle = true;
			return;
		}
		dfs(v);
	}
	vis[u] = 2;
}

void dfs2 (int u) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs2(v);
	}
	topo.push_back(u);
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}
	if (cycle) {
		cout << "NO" << '\n';
	} else {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			dfs2(i);
		}
		reverse(topo.begin(), topo.end());
		int num = 1;
		for (auto x : topo) {
			sol[x] = num++;
		}
		cout << "YES" << '\n';
		for (int i = 0; i < n; i++) {
			cout << sol[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
