#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], tin(MX), fup(MX);
int timer = 0, vis[MX];
map<pair<int, int>, int> id;
bool bridge = false;
vector<pair<int, pair<int, int>>> sol;

pair<int, int> fn (int a, int b) {
	return make_pair(min(a, b), max(a, b));
}

void dfs (int u, int par) {
	tin[u] = ++timer;
	fup[u] = tin[u];
	for (auto v : g[u]) {
		if (!tin[v]) {
			dfs(v, u);
			if (fup[v] > tin[u]) {
				bridge = true;
			}
			fup[u] = min(fup[u], fup[v]);
		} else if (par != v) {
			fup[u] = min(fup[u], tin[v]);
		}
	}
}

void dfs2 (int u, int par) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (v == par || vis[v] == 2) continue;
		int in = id[fn(u, v)];
		sol.push_back(make_pair(in, make_pair(u, v)));
		if (vis[v] == 0) dfs2(v, u);
	}
	vis[u] = 2;
}


int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		id[fn(u, v)] = i;
	}

	dfs(1, -1);
	
	if (bridge) {
		cout << 0 << '\n';
		return 0;
	}

	dfs2(1, -1);
	sort(sol.begin(), sol.end());

	for (auto cur : sol) {
		cout << cur.second.first << ' ' << cur.second.second << '\n';
	}
}
