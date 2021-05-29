#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> tin(MX), fup(MX), parent(MX, -1);
map<pair<int, int>, int> is_bridge;
vector<pair<int, int>> g[MX];
bool vis[MX];
int timer = 0, node[MX], n, m;
vector<int> tree[MX];

void dfs (int u, int par) {
	tin[u] = ++timer;
	fup[u] = tin[u];
	for (auto cur : g[u]) {
		int v, id;
		tie(v, id) = cur;
		if (!tin[v]) {
			dfs(v, u);
			if (fup[v] > tin[u]) {
				is_bridge[make_pair(u, v)] = 1;
				is_bridge[make_pair(v, u)] = 1;
			}
			fup[u] = min(fup[u], fup[v]);
		} else if (par != v) {
			fup[u] = min(fup[u], tin[v]);
		}
	}
}

void dfs2 (int u) {
	vis[u] = true;
	node[u] = timer;
	for (auto cur : g[u]) {
		int v, id;
		tie(v, id) = cur;
		if (vis[v] || is_bridge[make_pair(u, v)]) continue;
		dfs2(v);
	}
}

void dfs3 (int u, int par) {
	parent[u] = par;
	for (auto v : tree[u]) {
		if (v == par) continue;
		dfs3(v, u);
	}
}

int main () {
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(make_pair(v, i));
		g[v].push_back(make_pair(u, i));
		edges.push_back(make_pair(u, v));
	}

	dfs(1, -1);

	timer = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		timer++;
		dfs2(i);
	}

	map<pair<int, int>, int> id;
	for (int i = 0; i < m; i++) {
		int u, v;
		tie(u, v) = edges[i];
		if (is_bridge[make_pair(u, v)]) {
			id[make_pair(node[u], node[v])] = i + 1;
			id[make_pair(node[v], node[u])] = i + 1;
			tree[node[u]].push_back(node[v]);
			tree[node[v]].push_back(node[u]);
		}
	}

	dfs3(node[1], -1);

	vector<int> sol;
	int cur = node[n];
	while (parent[cur] != -1) {
		sol.push_back(id[make_pair(cur, parent[cur])]);
		cur = parent[cur];
	}

	sort(sol.begin(), sol.end());
	cout << (int) sol.size() << '\n';
	for (auto x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}
