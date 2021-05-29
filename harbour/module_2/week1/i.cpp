#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX], gt[MX], comp(MX), tout(MX), topo, gc[MX];
bool vis[MX];
int n, m, timer;

void dfs (int u) {
	tout[u] = timer++;
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
	topo.push_back(u);
}

void dfs2 (int u) {
	vis[u] = true;
	comp[u] = timer;
	for (auto v : gt[u]) {
		if (vis[v]) continue;
		dfs2(v);
	}
}

int main () {
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		g[u].push_back(v);
		gt[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}

	reverse(topo.begin(), topo.end());
	timer = 0;
	memset(vis, false, sizeof(vis));
	for (auto x : topo) {
		if (vis[x]) continue;
		dfs2(x);
		timer++;
	}

	for (auto edge : edges) {
		int u, v;
		tie(u, v) = edge;
		if (comp[u] == comp[v]) continue;
		gc[comp[u]].push_back(comp[v]);
	}

	int cc = -2;
	for (int i = 0; i < timer; i++) {
		if ((int) gc[i].size() == 0) {
			if (cc == -2) cc = i;
			else cc = -1;
		}
	}
	vector<int> sol;
	for (int i = 1; i <= n; i++) {
		if (comp[i] == cc) sol.push_back(i);
	}
	cout << (int) sol.size() << '\n';
	for (auto x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}
