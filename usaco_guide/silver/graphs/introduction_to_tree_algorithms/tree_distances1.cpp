#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 2e5 + 5;

vector<ll> g[MX], sol(MX);
ll childs[MX], totSum[MX], n;

void dfs1 (int v, int parent) {
	if (parent == -1) {
		sol[v] = totSum[v];
	} else {
		sol[v] = sol[parent] - (childs[v] + 1) + (n - (childs[v] + 1));
	}

	for (auto x: g[v]) {
		if (x == parent) continue;
		dfs1(x, v);
	}
}

void dfs (int v, int parent) {

	for (auto x: g[v]) {
		if (x == parent) continue;
		dfs(x, v);
		childs[v] += childs[x] + 1;
		totSum[v] += totSum[x] + childs[x] + 1;
	}
}

int main () {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, MX - 1);
	dfs1(0, -1);

	for (int i = 0; i < n; i++) {
		cout << sol[i] << (i == n - 1 ? '\n' : ' ');
	}
}
