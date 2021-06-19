#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
int depth[MX], sub[MX];
bool ind[MX];
ll sol = 0;

void dfs (int u, int par) {
	sub[u] = 1;
	for (auto v : g[u]) {
		if (v == par) continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		sub[u] += sub[v];
	}
}

void dfs2 (int u, int par, int cur) {
	if (ind[u]) {
		sol += cur;
	}
	int nw_cur = cur + (ind[u] ? 0 : 1);
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs2(v, u, nw_cur);
	}
}

bool comp (const int& a, const int& b) {
	return depth[a] - (sub[a] - 1) > depth[b] - (sub[b] - 1);
}

int main () {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	int in[n];
	iota(in, in + n, 0);
	sort(in, in + n, comp);
	for (int i = 0; i < k; i++) {
		ind[in[i]] = true;
	}
	dfs2(0, -1, 0);
	cout << sol << '\n';
}
