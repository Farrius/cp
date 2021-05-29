#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], gt[MX], gtr[MX], cc(MX), topo;
bool vis[MX];
int timer = 0;

void dfs (int u) {
	vis[u] = true;
	cc[u] = timer;
	for (auto v : gt[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

void dfst (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfst(v);
	}
	topo.push_back(u);
}

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		gt[v].push_back(u);
		edges.emplace_back(u, v);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfst(i);
	}
	reverse(topo.begin(), topo.end());
	
	memset(vis, false, sizeof(vis));
	for (int i : topo) {
		if (vis[i]) continue;
		timer++;
		dfs(i);
	}

	for (auto cur : edges) {
		int u, v;
		tie(u, v) = cur;
		if (cc[u] != cc[v]) {
			gtr[cc[u]].push_back(cc[v]);
		}
	}

	int sol = 0;
	for (int i = 1; i <= timer; i++) {
		if ((int) gtr[i].size() == 0) sol++;
	}
	cout << sol << '\n';
}
