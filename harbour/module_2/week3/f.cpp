#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 5e3 + 5;

int par[MX], sz[MX];
vector<int> mst_edges;
vector<pair<int, pair<int, int>>> edges;

int get (int x) {
	if (par[x] == x) return x;
	return par[x] = get(par[x]);
}

bool unite (int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return false;
	if (sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	par[y] = x;
	return true;
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(make_pair(w, make_pair(u, v)));
	}
	//kruskal
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		tie(u, v) = edges[i].second;
		if (unite(u, v)) mst_edges.push_back(i);
	}
	//quitar un edge y contar
	ll sol = 1e18;
	for (auto ii : mst_edges) {
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
		ll cur = 0;
		int nodes = 0;
		for (int i = 0; i < m; i++) {
			if (ii == i) continue;
			int u, v;
			tie(u, v) = edges[i].second;
			if (unite(u, v)) {
				nodes++;
				cur += edges[i].first;
			}
		}
		if (nodes == n - 1) sol = min(sol, cur);
	}
	cout << sol << '\n';
}
