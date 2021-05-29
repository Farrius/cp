#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], topo;
bool vis[MX], vis2[MX];
int dist = 0;

void dfs (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
	topo.push_back(u);
}

void dfs2 (int u) {
	vis[u] = true;
	vis2[u] = true;
	dist++;
	for (auto v : g[u]) {
		if (vis2[v]) continue;
		dfs2(v);
	}
}

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}
	reverse(topo.begin(), topo.end());
	memset(vis, false, sizeof(vis));
	int mx = 0;
	for (auto u : topo) {
		if (vis[u]) continue;
		memset(vis2, false, sizeof(vis2));
		dist = 0;
		dfs2(u);
		mx = max(mx, dist);
	}
	cout << mx << '\n';
}
