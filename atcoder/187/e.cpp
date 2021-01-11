#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
ll d[MX], w[MX];

void dfs (int v, int p) {
	d[v] = d[p] + 1;
	for (auto u : g[v]) {
		if (u == p) continue;
		dfs(u, v);
	}
}

void dfs1 (int v, int p, ll cur) {
	w[v] += cur;
	for (auto u : g[v]) {
		if (u == p) continue;
		dfs1(u, v, w[v]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(d, -1, sizeof(d));
	int n;
	cin >> n;
	vector<pair<int, int>> edges;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.push_back({u, v});
	}
	dfs(0, 0);
	int q;
	cin >> q;
	while (q--) {
		int t, e, x;
		cin >> t >> e >> x;
		e--;
		int u, v;
		tie(u, v) = edges[e];
		if (t == 1) {
			if (d[u] < d[v]) {
				w[0] += x;
				w[v] -= x;
			} else {
				w[u] += x;
			}
		} else {
			if (d[u] > d[v]) {
				w[0] += x;
				w[u] -= x;
			} else {
				w[v] += x;
			}
		}
	}
	dfs1(0, -1, 0);
	for (int i = 0; i < n; i++) {
		cout << w[i] << '\n';
	}
}
