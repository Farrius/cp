#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], tree[MX], tin(MX), fup(MX), comp(MX), depth(MX);
map<pair<int, int>, int> bridge;
int timer = 0;
bool vis[MX];

void dfs (int u, int par) {
	tin[u] = ++timer;
	fup[u] = tin[u];
	for (auto v : g[u]) {
		if (!tin[v]) {
			dfs(v, u);
			if (fup[v] > tin[u]) {
				bridge[make_pair(u, v)] = 1;
				bridge[make_pair(v, u)] = 1;
			}
			fup[u] = min(fup[u], fup[v]);
		} else if (v != par) {
			fup[u] = min(fup[u], tin[v]);
		}
	}
}

void dfs2 (int u) {
	vis[u] = true;
	comp[u] = timer;
	for (auto v : g[u]) {
		if (vis[v] || bridge[make_pair(u, v)]) continue;
		dfs2(v);
	}
}

int node = 0, mx = 0;

void dfs3 (int u, int par) {
	for (auto v : tree[u]) {
		if (v == par) continue;
		depth[v] = depth[u] + 1;
		if (depth[v] > mx) {
			mx = depth[v];
			node = v;
		}
		dfs3(v, u);
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.push_back(make_pair(u, v));
	}

	dfs(1, -1);

	timer = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		timer++;
		dfs2(i);
	}
	
	int sol = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		tie(u, v) = edges[i];
		if (bridge[make_pair(u, v)]) {
			sol++;
			tree[comp[u]].push_back(comp[v]);
			tree[comp[v]].push_back(comp[u]);
		}
	}

	dfs3(comp[1], -1);
	fill(depth.begin(), depth.end(), 0);
	mx = 0;
	dfs3(node, -1);
	sol -= depth[node];
	cout << sol << '\n';
}
