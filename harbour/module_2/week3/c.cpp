#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 2e5 + 5;

vector<int> g[MX];
int par[MX], sz[MX];

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
	vector<int> sol;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.emplace_back(u, v);
	}

	int cc = n;
	for (int i = m - 1; i >= 0; i--) {
		sol.push_back(cc);
		int u, v;
		tie(u, v) = edges[i];
		if (unite(u, v)) cc--;
	}

	reverse(sol.begin(), sol.end());
	for (auto x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}
