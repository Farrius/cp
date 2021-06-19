#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
set<pair<int, int>> nop;
int n, sub[MX], obj;
bool fuera = false;

void dfs (int u, int par) {
	sub[u] = 1;
	for (auto v : g[u]) {
		if (v == par || nop.count(make_pair(min(v, u), max(v, u)))) continue;
		dfs(v, u);
		sub[u] += sub[v];
	}
}

void dfs2 (int u, int par) {
	if (fuera) return;
	for (auto v : g[u]) {
		if (v == par || nop.count(make_pair(min(v, u), max(v, u)))) continue;
		if (sub[v] == obj) {
			fuera = true;
			nop.insert(make_pair(min(v, u), max(v, u)));
			return;
		}
		dfs2(v, u);
	}
}

int main () {
	cin >> n;
	if (n % 3 != 0) {
		cout << "NO" << '\n';
		return 0;
	} else {
		obj = n/3;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	dfs2(1, -1);
	if (nop.empty()) {
		cout << "NO" << '\n';
		return 0;
	}
	fuera = false;
	dfs(1, -1);
	dfs2(1, -1);
	if ((int) nop.size() < 2) {
		cout << "NO" << '\n';
		return 0;
	} else {
		cout << "YES" << '\n';
		for (auto x : nop) {
			cout << x.first << ' ' << x.second << '\n';
		}
	}
}
